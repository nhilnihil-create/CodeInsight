//#include <tourist>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <queue>
#include <tuple>
#include <deque>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <utility>
#include <complex>
#include <functional>
using namespace std;
const int MOD = 1000000007;
typedef long long ll;
typedef pair<ll, ll> p;
const int INF = (1 << 28);
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int Dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, Dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
#define yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define no cout << "No" << endl
#define NO cout << "NO" << endl
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
//setprecision(15)有効数字15桁
//-std=c++14
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}
struct edge {
    int to, cost;
};
ll n;
string s;
struct fenwick_tree {
    typedef ll T;
    T n;
    vector<T> bit;

    // 各要素の初期値は 0
    fenwick_tree(T num) : bit(num+1, 0) { n = num; }

    // a_i += w
    void add(T i, T w) {
        for (T x = i; x <= n; x += x & -x) {
            bit[x] += w;
            bit[x]%=MOD;
        }
    }
    // [1, i] の和を計算.
    T sum(T i) {
        T ret = 0;
        for (T x = i; x > 0; x -= x & -x) {
            ret += bit[x];
            ret%=MOD;
        }
        return ret;
    }
    // [left+1, right] の和を計算.
    T sum(T left, T right) {
        return (sum(right) - sum(left)+MOD)%MOD;
    }
};
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n>>s;
    ll dp[n+1][n+1];//i番目まで見てi番目の数より小さい数字がj個使われている
    memset(dp,0,sizeof dp);
    for(int i=0;i<=n;i++){
        dp[0][i]=1;
    }
    for(ll i=1;i<n;i++){
        fenwick_tree tree(n);
        for(ll j=1;j<=n-i+1;j++){
            //cout<<j<<" "<<dp[i-1][j]<<"\n";
            tree.add(j,dp[i-1][j]);
        }
        for(ll j=1;j<=n-i;j++){
            if(s[i-1]=='<'){
                dp[i][j]=tree.sum(0,j);
            }
            else{
                dp[i][j]=tree.sum(j,n);
            }
        }
    }
    cout << dp[n-1][1] << "\n";
}

