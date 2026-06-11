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
#define ALL(a)  (a).begin(),(a).end()
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<long long, long long>;
const int INF = numeric_limits<int>::max();
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }

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

bool is_prime(ll n) {
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return n != 1;
}

vector<vector<int>> d(10, vector<int>(10, 1000000));

void warshall_floyd(int n) {
    rep(k,n) rep(i,n) {
        rep(j,n) {
            d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
        }
    }
}

int main()
{
    ll a, b, k; cin >> a >> b >> k;

    rep(i,k) {
        if (i % 2 == 0) {
            if (a % 2 == 1)
                a--;
            b += a/2;
            a /= 2;
        } else {
            if (b % 2 == 1)
                b--;
            a += b/2;
            b /= 2;
        }
    }
    cout << a << " " << b << endl;
            
    return 0;
}
