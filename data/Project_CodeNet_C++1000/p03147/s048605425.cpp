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

int ans = 0;
int h[100];
int n;

void solve(int l, int r) {
    if (l < 0 || (h[l] == 0 && h[r] == 0))
        return;
    for (int i = l; i <= r; i++) {
        h[i]--;
    }
    ans++;
    int start = -1, end = 101;
    for (int i = l; i <= r; i++) {
        if (h[i] > 0) {
            if (start < 0) {
                start = i;
            }
        }
        if (h[i] == 0) {
            solve(start, i - 1);
            start = -1;
        }
        if (i == r) {
            solve(start, i);
        }
    }
}

int main()
{
    cin >> n;
    int m = INF;
    rep(i,n) {
        int tmp;
        cin >> tmp;
        m = min(m, tmp);
        h[i] = tmp;
    }
    int start = -1;
    for (int i = 0; i < n; i++) {
        if (h[i] > 0) {
            if (start < 0) {
                start = i;
            }
        }
        if (h[i] == 0) {
            solve(start, i - 1);
            start = -1;
        }
        if (i == n-1) {
            solve(start, i);
        }
    }
    solve(0, n-1); 
    cout << ans << endl;
    return 0;
}
