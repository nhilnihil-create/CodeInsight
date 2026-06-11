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

const vector<int> ToBinary(LLONG n, int len = 0)
{
    vector<int> ret;
    while (n > 0)
    {
        ret.push_back(n % 2);
        n /= 2;
    }
    while (ret.size() < len)
    {
        ret.push_back(0);
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int main()
{
    // Aiを２進数表示したときの各桁について0/1の数を数え
    // 数が多い側と逆の数をXのその桁の数にしていく
    int N;
    LLONG K;
    cin >> N >> K;
    vector<LLONG> As(N);
    for (auto &Ai : As) cin >> Ai;
    int len = ToBinary(max(*max_element(As.begin(), As.end()), K)).size();
    vector<vector<int>> biAs(N);
    for (int i = 0; i < N; ++i)
    {
        biAs[i] = ToBinary(As[i], len);
        len = max(len, static_cast<int>(biAs[i].size()));
    }
    // Asの各数ごとに各桁の0/1の数を数えておく
    vector<int> zeroNums(len, 0);
    for (const auto &biAi : biAs)
    {
        for (int i = 0; i < len; ++i)
        {
            if (biAi[i] == 0) ++zeroNums[i];
        }
    }
    // 上の桁から順にXの値を決めていく:O(log2(K))
    LLONG ans = 0;
    LLONG digit = (1LL << len) / 2;
    bool hasDecreased = false;
    const auto biK = ToBinary(K, len);
    for (int i = 0; i < len; ++i, digit /= 2)
    {
        bool isMoreZero = zeroNums[i] > (N - zeroNums[i]);
        int Ki = biK[i];
        if (Ki == 1)
        {
            if (isMoreZero)
            {
                // X(i) = 1 とし，Ai の 0 の数だけ f(X) が増える
                ans += digit * zeroNums[i];
            }
            else
            {
                // X(i) = 0 とし，Ai の 1 の数だけ f(X) が増える
                // さらに，K が 1 のところを 0 に変えるので以降は X < K となる
                ans += digit * (N - zeroNums[i]);
                hasDecreased = true;
            }
        }
        else
        {
            if (isMoreZero)
            {
                // X(i) = 1 とし，Ai の 0 の数だけ f(X) が増える
                // ただし，K が 0 の桁なので，既に X < K のときのみ 0 -> 1 に変えられる
                if (hasDecreased) ans += digit * zeroNums[i];
                // 既に X < K でない場合は 0 -> 1 に増やせないので 0 のまま
                else ans += digit * (N - zeroNums[i]);
            }
            else
            {
                // X(i) = 0 とし，Ai の 1 の数だけ f(X) が増える
                ans += digit * (N - zeroNums[i]);
            }
        }
    }
    cout << ans << endl;
}
