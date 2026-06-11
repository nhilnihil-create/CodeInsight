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
const ll INF = 1e17;
const int inf = 1e5;
typedef long double ld;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll a, ll b) { return a ? gcd(b%a, a) : b; }
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
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
struct SegmentTree{
  int N;
  vector<int> node;
  public :
    void intit(vector<int>v){
      int sz = v.size();
      N=1;
      while(N<sz) N*=2;
      node.resize(N);
      for(int i=0 ; i<sz ; i++) node[i+N-1] = v[i];
      for(int i=N-2 ; i>=0 ; i--) node[i] = min(node[i*2+1], node[i*2+2]);
    }
    void update(int x, int val){
      x += N-1;
      node[x+N-1] = val;
      while(x>0){
        x = (x-1)/2;
        node[x] = min(node[x*2+1], node[x*2+2]);
      }
    }
    int getmin(int a, int b, int k, int l, int r){
      if(b<=l || r<=a) return inf;
      else if(a<=l && r<=b) return node[k];
      else{
        int vl = getmin(a, b, 2*k+1, l, (l+r)/2);
        int vr = getmin(a, b, 2*k+2, (l+r)/2, r);
        return min(vl, vr);
      }
    }
};const int MAX = 510000;
const int MOD = 1000000007;
long long fac[MAX], finv[MAX], inv[MAX];
// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
int main(){
  string s,t; cin>>s>>t;
  int ok = 1;
  map<char, int> ma;
  int N = s.size();
  for(char c='a' ; c<='z' ; c++) ma[c] = c - 'a';
  vector<set<int>> set1(26), set2(26);
  int cnt = 0;
  rep(i,0,N){
    int now = ma[s[i]];
    set1[now].insert(i);
    now = ma[t[i]];
    set2[now].insert(i);
  }
  rep(i,0,26){
    char c = ' ';  cnt = 0;
    for(auto j : set1[i]){
      if(cnt==0){
        cnt++;  c = t[j];
        continue;
      }
      if(c != t[j]) ok = 0;
    }
    cnt = 0;
    for(auto j : set2[i]){
      if(cnt==0){
        cnt++;  c = s[j];
        continue;
      }
      if(c != s[j]) ok = 0;
    }
  }
  string ans = "No";
  if(ok){
    ans = "Yes";
  }
  cout<<ans<<endl;
  return 0;
}
