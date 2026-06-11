#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

const vector<int> ToBinary(const int digitNum, LLONG n)
{
    vector<int> ret(digitNum);
    for (int i = digitNum - 1; i >= 0; --i)
    {
        ret[i] = n % 2;
        n /= 2;
    }
    return ret;
}

const LLONG ToLLONG(const int digitNum, const vector<int> &binary)
{
    LLONG ret = 0LL;
    LLONG base = 1LL;
    for (int i = digitNum - 1; i >= 0; --i)
    {
        ret += binary[i] * base;
        base *= 2;
    }
    return ret;
}

int main()
{
    int N, K; cin >> N >> K;
    LLONG sum = 0LL;
    vector<LLONG> cumSums(N + 1);
    for (int i = 0; i < N; ++i)
    {
        LLONG ai; cin >> ai;
        sum += ai;
        cumSums[i + 1] = sum;
    }
    // N <= 1e3 と小さいので，部分列の個数は高々 1e6 個
    // K 個の部分列の論理積を計算してなるべく大きな値を作るためには
    // なるべく上位のビットで K 個全てで 1 が立っている組を選ぶ必要がある
    // -> 全ての部分列の和について，上位ビットから順に 1 が立っているものを選んでいく:O(digitNum * N^2)
    const int digitNum = 40;    // 総和の最大値が 10^12 より，40桁あれば十分
    vector<vector<int>> binaries;
    for (int l = 0; l < N; ++l)
    {
        for (int r = l; r < N; ++r)
        {
            binaries.push_back(ToBinary(digitNum, cumSums[r + 1] - cumSums[l]));
        }
    }
    for (int d = 0; d < digitNum; ++d)
    {
        vector<vector<int>> ones;
        for (const auto &binary : binaries)
        {
            if (binary[d] == 1)
            {
                ones.push_back(binary);
            }
        }
        // １が立っているものがK個以上あれば全て残す
        if (ones.size() > K)
        {
            binaries = ones;
        }
        // １が立っているものがK個であればそれらを選択して終了
        else if (ones.size() == K)
        {
            binaries = ones;
            break;
        }
        // １が立っているものがK個未満であれば，どう選んでもANDをとったときこの桁は０
        // -> この桁だけでは選択しようがないので次に移る
        else
        {
            continue;
        }
    }
    LLONG ans = ToLLONG(digitNum, binaries.front());
    for (const auto &binary : binaries)
    {
        ans = ans & ToLLONG(digitNum, binary);
    }
    cout << ans << endl;
}
