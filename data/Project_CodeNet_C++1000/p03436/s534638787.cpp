#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
#include<complex>
#include<numeric>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ul;
typedef unsigned int ui;
typedef pair<int, int>P;
typedef pair<ll, ll> LP;
typedef long double ld;
typedef pair<ld, ld> LDP;
typedef vector<vector<ll>> mat;
typedef vector<ll> vec;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define all(v) (v).begin(),(v).end()
const ll mod = 1000000007;
const ll INF = mod * mod;
const ld eps = 1e-12;
const ld pi = acos(-1.0);
//int qp(int a,ll b){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}
ll qp(ll a,ll b,int mo){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;} // 最大公約数
ll lcm (ll a, ll b){return a/gcd(a,b)*b;} // 最小公倍数
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const deque<T> &vec){ os << "deq["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }
template<typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool chmin(T &m, const T q) { if (q < m) {m = q; return true;} else return false; }
template<typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template<typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
template<typename T1, typename T2> pair<T1, T2> operator<(const pair<T1, T2> l, const pair<T1, T2> r) { return (l.first < r.first); }
template<typename T1, typename T2> pair<T1, T2> operator>(const pair<T1, T2> l, const pair<T1, T2> r) { return (l.first > r.first); }


void solve() {
    int H,W; cin >> H >> W;
    char stage[H][W];
    int cost[H][W];
    int white_co = 0;
    int INF = 3000;
    rep(i,H){
        rep(j,W){
            char c; cin >> c;
            stage[i][j] = c;
            cost[i][j] = INF;
            if(c=='.') {
                white_co++;
            }
        }
    }

    queue<P> node;
    node.push(P(0,0));
    cost[0][0] = 0;

    while(!node.empty()){
        int x = node.front().first;
        int y = node.front().second;
        node.pop();

        rep(i,4){
            int tx = x + dx[i];
            int ty = y + dy[i];

            if(tx<0 || tx>=H || ty<0 || ty>=W) continue;
            if(stage[tx][ty] == '#') continue;

            if(chmin(cost[tx][ty], cost[x][y]+1)){
                node.push(P(tx,ty));
            }
        }
    }

    int res;

    if(cost[H-1][W-1] == INF)res = -1;
    else res = white_co - 1 - cost[H-1][W-1];

    cout << res << endl;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    std::cout << fixed << setprecision(10);
    solve();
    return 0;
}
