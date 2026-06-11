// https://atcoder.jp/contests/tenka1-2017/tasks/tenka1_2017_c
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
    ll N;
    scanf("%lld", &N);
    for (ll h = 1; h <= 3500; ++h)
    {
        for (ll n = 1; n <= 3500; ++n)
        {
            ll f = N * h * n;
            ll d = 4LL * n * h - N * h - N * n;
            if (d <= 0) continue;
            ll r = f % d;
            if (r != 0) continue;
            ll w = f / d;
            ll q0 = (n * w + h * w + n * h) / 4LL;
            ll r0 = (n * w + h * w + n * h) % 4LL;
            ll q1 = (n * h * w) / N;
            ll r1 = (n * h * w) % N;
            if (r0 == 0 && r1 == 0 && q0 == q1)
            {
                printf("%lld %lld %lld\n", h, n, w);
                return 0;
            }
        }
    }
    return 0;
}
