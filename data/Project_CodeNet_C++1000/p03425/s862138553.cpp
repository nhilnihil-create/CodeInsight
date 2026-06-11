#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <iomanip>
#include <bitset>
#include <set>
#include <map>
#include <stdio.h>
#include <numeric>
#include <cstring>

#define rep(i,n) for (int i = 0; i < (n); i++)
#define rep1(i,n) for (int i = 1; i < (n); i++)
#define FOR(i,a,b) for (int i=(a); i < (b); i++)
#define MOD 1000000007 //10^9+7
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;
const int INF = numeric_limits<int>::max();
const ll INFL = numeric_limits<ll>::max();


// 負の数にも対応した % 演算
long long mod(long long val, long long m) {
    long long res = val % m;
    if (res < 0) res += m;
    return res;
}

//greatest common divisor
long long gcd(ll a, ll b) 
{
    if (a % b == 0) {
        return b;
    } else {
        return gcd(b, a % b);
    }
}

//least common multiple
long long lcm(ll a, ll b)
{
    return a / gcd(a, b) * b ;
}

ll factorial(ll n) {
    ll res = 1;
    for (ll i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}

int main()
{
    int n; cin >> n;
    vector<ll> s(5,0);
    int p[10]={0,0,0,0,0,0,1,1,1,2};
    int q[10]={1,1,1,2,2,3,2,2,3,3};
    int r[10]={2,3,4,3,4,4,3,4,4,4};
    rep(i,n) {
        string tmp; cin >> tmp;
        if (tmp[0] == 'M') {
            s[0]++;
        }
        if (tmp[0] == 'A') {
            s[1]++;
        }
        if (tmp[0] == 'R') {
            s[2]++;
        }
        if (tmp[0] == 'C') {
            s[3]++;
        }
        if (tmp[0] == 'H') {
            s[4]++;
        }
    }

    ll ans = 0;
    rep(i,10) {
        ans += s[p[i]] * s[q[i]] * s[r[i]];
    }
    printf ("% lld\n",ans);
    return 0;
}
