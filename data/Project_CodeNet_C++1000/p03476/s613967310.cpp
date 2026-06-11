// https://atcoder.jp/contests/abc084/tasks/abc084_d
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <bitset>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define REP(i, n) for(size_t i = 0; i < (n); ++i)

int main()
{
    ll Q;
    cin >> Q;
    vector<ll> l(Q), r(Q);
    REP(i, Q) cin >> l[i] >> r[i];
    vector<ll> isprime(100011, 0);
    size_t N = isprime.size();
    for (size_t n = 2; n < N; ++n)
    {
        if (isprime[n] == -1)
            continue;
        
        isprime[n] = 1;
        for (size_t k = n + n; k < N; k += n)
        {
            isprime[k] = -1;
        }
    }

    vector<ll> cnt(N, 0);
    for (size_t n = 3; n < N; n += 2)
    {
        if (isprime[n] == 1 && isprime[(n + 1) / 2] == 1)
        {
            cnt[n] = cnt[n - 2] + 1;
            cnt[n - 1] = cnt[n - 2];
        }
        else
        {
            cnt[n] = cnt[n - 2];
            cnt[n - 1] = cnt[n - 2];
        }
        
    }

    vector<ll> res(Q, 0);
    REP(i, Q)
    {
        res[i] = cnt[r[i]] - cnt[l[i] - 1];
    }

    REP(i, Q)
    {
        cout << res[i] << endl;
    }
    return 0;
}
