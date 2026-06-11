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
const int INF = numeric_limits<int>::max();

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

int main()
{
    int n,k; cin >> n ;
    vector<ll> x(n);
    rep(i,n) cin >> x[i];

    vector<ll> tmp = x;
    sort(tmp.begin(), tmp.end());
    long double median = (tmp[n/2-1] + tmp[n/2]) / 2.0;

    rep(i,n) {
        if(x[i] < median) {
            cout << tmp[n/2] << endl;
        } else {
            cout << tmp[n/2-1] << endl;
        }
    }
    return 0;
}
