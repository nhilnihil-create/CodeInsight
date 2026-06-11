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
typedef long double ld;
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
ll gcd(ll a, ll b) { return a ? gcd(b%a, a) : b; };
int main(){
  int N;  cin>>N;
  vector<ll> a(N),b(N),c(N),d(N),e(N);
  vector<P> p(N);
  vector<ll> other(N);
  rep(i,0,N) cin>>a[i], c[i]=e[i]=a[i];
  rep(i,0,N) cin>>b[i], d[i]=b[i];
  rep(i,0,N) p[i]=mp(a[i],b[i]);
  rep(i,0,N){

  }
  sort(all(p));
  sort(all(c)); sort(all(d));
  bool ok=true;
  map<ll,ll> ma;
  ll sum = 0;
  int cnt=0;
  rep(i,0,N){
    if(a[i]<b[i]) cnt++, sum += b[i]-a[i];
  }
  priority_queue<ll> que;
  rep(i,0,N){
    if(a[i]>b[i]){
      que.push(a[i]-b[i]);
    }
  }
  while(que.size()){
    if(sum<=0)break;
    sum -= que.top();
    que.pop();
    cnt++;
  }
  if(sum<=0)cout << cnt << endl;
  else cout<<-1<<endl;
  return 0;
}
