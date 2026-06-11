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

#define rep(i,n) for (long long int i = 0; i < (n); i++)
#define rep1(i,n) for (long long int i = 1; i < (n); i++)
#define FOR(i,a,b) for (int i=(a); i < (b); i++)
#define INF 100000000000
#define MOD 1000000007 //10^9+7
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 負の数にも対応した % 演算
long long mod(long long val, long long m) {
    long long res = val % m;
    if (res < 0) res += m;
    return res;
}

long long gcd(ll a, ll b) 
{
    if (a % b == 0) {
        return b;
    } else {
        return gcd(b, a % b);
    }
}

long long lcm(ll a, ll b)
{
    return a / gcd(a, b) * b ;
}

int main()
{
    vector<int> v(3);
    rep(i,3) cin >> v[i];
    sort(v.begin(), v.end());

    v[0] = v[2] - v[0];
    v[1] = v[2] - v[1];
    int ans = 0;
    if (v[0] % 2 == 0 && v[1] % 2 == 0) {
        ans = v[0]/2 + v[1]/2;
    }
    if (v[0] % 2 == 1 && v[1] % 2 == 1) {
        ans = 1 + (v[0]-1)/2 + (v[1]-1)/2;
    }
    if (v[0] % 2 != v[1] % 2) {
        ans = v[1] + (v[0]-v[1])/2 + 2;
    }
    cout << ans << endl;
    return 0;
}
