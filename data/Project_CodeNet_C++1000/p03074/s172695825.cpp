#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,int> pli;
typedef pair<int,int> pii;
#define rep(i,a,b) for(ll i=a ; i<b ; i++)
#define qrep(que, ite) for(auto ite=begin(que) ; ite!=end(que) ; ite++)
const int max_n = 1e5;
const ll mod = 1e9+7;
const ll INF = 1LL<<60;
const int inf = 1e5;
//typedef long double ld;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
ll mo = 998244353;
struct UnionFind {
    vector<int> par;

    UnionFind(int n) : par(n, -1) { }
    void init(int n) { par.assign(n, -1); }

    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }

    int size(int x) {
        return -par[root(x)];
    }
};
int main(){
  int n,k;  cin>>n>>k;
  string s; cin>>s;
  vector<int> v;
  if(s[0]=='0') v.pb(0);
  for(int i=0 ; i<n ; ){
    int j=i;
    while(s[i]==s[j] && j<n) j++;
    v.pb(j-i);
    i = j;
  }
  if(s.back()=='0') v.pb(0);
  vector<ll> sum(v.size()+1, 0);
  rep(i,0,v.size()){
    sum[i+1] = sum[i] + v[i];
  }
  ll ma=-1;
  for(int i=0 ; i<sum.size() ; i+=2){
    int left= (i+2*k+1>=sum.size() ? sum.size()-1 : i+2*k+1);
    chmax(ma, sum[left] - sum[i]);
  }
  cout << ma << endl;
  return 0;
}
