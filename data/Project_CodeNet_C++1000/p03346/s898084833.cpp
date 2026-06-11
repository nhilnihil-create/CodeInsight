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
const LLONG MOD = 998244353;

int main()
{
    int N;
    cin >> N;
    vector<int> P(N);
    for (auto &Pi : P)
    {
        cin >> Pi;
        --Pi;
    }
    // コーナーケース
    if (N == 1){ cout << 0 << endl; return 0; }
    // 各数字がPの何番目に入っているか調べる
    vector<int> Q(N);
    for (int i = 0; i < N; ++i)
    {
        Q[P[i]] = i;
    }
    // 数字iとi+1について，（iの場所）＜（i+1の場所）ならば
    // これらについては動かす必要がない（間の数を前後に移せばよい）
    // 動かす必要がない連番のうち，最大長のもの l,l+1,...,r-1,rを探す
    // しゃくとり法で探す：O(N)
    int maxLen = 0;
    for (int l = 0; l < N - 1;)
    {
        int r = l;
        for (; r < N - 1; ++r)
        {
            if (Q[r] > Q[r + 1]) break;
        }
        maxLen = max(maxLen, r - l + 1);
        l = r + 1;
    }
    // 0,...,l-1 および r+1,...,N-1 をそれぞれ前後に動かせばよい
    cout << N - maxLen << endl;
}
