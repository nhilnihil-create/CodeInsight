#include <bits/stdc++.h>
#define exrep(i, a, b) for(long long i = a; i <= b; i++)
#define rep(i,n)for(long long i=0;i<(long long)(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
const ll MOD=1e9+7;
const ll INF=1e18;
const int MAX=110000;
const double pi=acos(-1);
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

ll gcd(ll x, ll y){
  if(x%y==0)return y;
  return gcd(y,x%y);
}
ll lcm(ll x,ll y){
  return x/gcd(x,y)*y;
}
template<class Abel> struct UnionFind {
    vector<int> par;
    vector<int> rank;
    vector<Abel> diff_weight;

    UnionFind(int n = 1, Abel SUM_UNITY = 0) {
        init(n, SUM_UNITY);
    }

    void init(int n = 1, Abel SUM_UNITY = 0) {
        par.resize(n); rank.resize(n); diff_weight.resize(n);
        for (int i = 0; i < n; ++i) par[i] = i, rank[i] = 0, diff_weight[i] = SUM_UNITY;
    }

    int root(int x) {
        if (par[x] == x) {
            return x;
        }
        else {
            int r = root(par[x]);
            diff_weight[x] += diff_weight[par[x]];
            return par[x] = r;
        }
    }

    Abel weight(int x) {
        root(x);
        return diff_weight[x];
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y, Abel w) {
        w += weight(x); w -= weight(y);
        x = root(x); y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y), w = -w;
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        diff_weight[y] = w;
        return true;
    }

    Abel diff(int x, int y) {
        return weight(y) - weight(x);
    }
};
int h,w,d,q;
int a[400][400];


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false); 
  
  ll n;
  cin >> n;
  string s="";
  while(true){
    ll q=n/(-2);
    ll r=n-q*(-2);
    if(r==-1){
      q++;
      r=1;
    }
    s=char(r+'0')+s;
    n=q;
    if(n==1 ||n==0)break;
  }
  if(n==1)s=char(n+'0')+s;
  cout << s << endl;  
}
