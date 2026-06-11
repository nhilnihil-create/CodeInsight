#include <bits/stdc++.h>

// #include <iostream> // cout, endl, cin
// #include <string> // string, to_string, stoi
// #include <vector> // vector
// #include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
// #include <utility> // pair, make_pair
// #include <tuple> // tuple, make_tuple
// #include <cstdint> // int64_t, int*_t
// #include <cstdio> // printf
// #include <map> // map
// #include <queue> // queue, priority_queue
// #include <set> // set
// #include <stack> // stack
// #include <deque> // deque
// #include <unordered_map> // unordered_map
// #include <unordered_set> // unordered_set
// #include <bitset> // bitset
// #include <climits>
// #include <cmath>
// #include <iomanip>
// #include <functional>
// #include <numeric>
// #include <random>

using namespace std;
    
#define int long long
#define pb push_back
#define F first
#define S second
#define FOR(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define rep(i,n) FOR(i,0,n)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define ve vector
#define vi vector<int>
#define vp vector<pair<int,int>>
#define vvi vector<vector<int>>
#define pint pair<int, int>

template<typename T> using pq = priority_queue<T,vector<T>,greater<T>>; 
using ll = long long;
ll INF = LLONG_MAX / 4000 - 100;
ll mod = 1e9 + 7;
int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1};
vector<ll> prime;
    
class fact {
public:
    int fmod = 1e9+7;
    vector<int> fac, inv;
    fact (int n, int Mod = 1e9+7) {
        fmod = Mod;
        fac = vector<int>(n,0);
        inv = vector<int>(n,0);
        fac[0] = 1; for (int i = 1; i < n; i++) fac[i] = fac[i-1] * i % fmod;
        for (int i = 0;i < n;i++) inv[i] = fact::POW(fac[i],fmod-2);
    }
    ll nCr(ll n, ll r) {if(n < r) return 0; return (fac[n] * inv[r] % fmod) * inv[n-r] % fmod;}
    ll POW(ll a, ll b) {ll c = 1; while (b > 0) {if (b & 1) {c = a * c%fmod;}a = a * a%fmod; b >>= 1;}return c;}
    inline int operator [] (int i) {return fac[i];}
};
    
template <class T = ll> T in() {T x; cin >> x; return (x);}
void DEBUG(vector<int> a) {for(int i=0;i<a.size();i++)cout<<a[i]<<" ";cout<<endl;}
void EMP(int x) {cout<<"!!!"<<x<<"!!!"<<endl;}
ll GCD(ll a, ll b) {ll c; while (b != 0) {c = a % b; a = b; b = c;}return a;}
ll LCM(ll a, ll b) {return (a / GCD(a, b)) * (b / GCD(a, b)) * GCD(a, b);}
ll POW(ll a, ll b) {ll c = 1; while (b > 0) {if (b & 1) {c = a * c%mod;}a = a * a%mod; b >>= 1;}return c;}
void PRI(ll n) {bool a[n + 1LL]; for (int i = 0; i < n + 1LL; i++) {a[i] = 1LL;}for (int i = 2; i < n + 1LL; i++) {if (a[i]) {prime.pb(i); ll b = i; while (b <= n) {a[b] = 0; b += i;}}}}
template <typename T> T chmin(T& a, T b) {if(a>b)a=b;return a;}
template <typename T> T chmax(T& a, T b) {if(a<b)a=b;return b;}
bool isSqrt(ll a) {return pow(sqrt(a),2) == a ? 1 : 0;}
void YesNo(bool a) {if (a) cout << "Yes"; else cout << "No"; cout << endl;}
void yesno(bool a) {if (a) cout << "yes"; else cout << "no"; cout << endl;}
void YESNO(bool a) {if (a) cout << "YES"; else cout << "NO"; cout << endl;}
double dis(int x1, int x2, int y1, int y2) {
    return sqrt((double)abs(x1-x2)*(double)abs(x1-x2)+(double)abs(y1-y2)*(double)abs(y1-y2));
}

class UnionFind {
private:
    vector<int> par;
public:
    UnionFind(int N) { par = vector<int>(N, -1); }
    int find(int x);
    ll size(int x);
    void unite(int x, int y);
    bool same(int x, int y);
};

int UnionFind::find(int x) {
    if (par[x] < 0) return x;
    else return par[x] = find(par[x]);
}
 
ll UnionFind::size(int x) {
    return -par[find(x)];
}
 
void UnionFind::unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    //大きい方に小さい方をくっ付ける
    if (size(x) < size(y)) swap(x, y);
    par[x] += par[y];
    par[y] = x;
}
 
bool UnionFind::same(int x, int y) {
    x = find(x);
    y = find(y);
    return x == y;
}

using pi = pair<int, int>;

bool solve() {
  int n; cin >> n;
  vp ab(n);
  int sum = 0;
  int mi = INF;
  rep (i, n) {
    cin >> ab[i].F >> ab[i].S;
    sum += ab[i].F;
    if (ab[i].F > ab[i].S) chmin(mi, ab[i].S);
  }
  sort(all(ab), [&](pi a, pi b){
    if (a.S-a.F!=b.S-b.F) return a.S-a.F < b.S-b.F;
    return a.S < b.S;
  });
  if (ab[0].F == ab[0].S) cout << 0 << endl;
  else cout << sum-mi << endl;
}
main() {
    ios::sync_with_stdio(false);
    solve();
}
