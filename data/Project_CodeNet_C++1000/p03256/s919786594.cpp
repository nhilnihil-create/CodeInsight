#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
using ld = long double;
template<typename T> using V = vector<T>;
template<typename T> using VV = vector<vector<T>>;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define siz(v) (ll)(v).size()
#define rep(i,a,n) for(ll i=a;i<(ll)(n);++i)
#define repr(i,a,n) for(ll i=n-1;(ll)a<=i;--i)
#define lb lower_bound
#define ub upper_bound
#define ENDL '\n'
typedef pair<int,int> Pi;
typedef pair<ll,ll> PL;
const ll mod = 1000000007;
const ll INF = 1000000099;
const ll LINF = (ll)(1e18 +99);
const vector<ll> dx={-1,1,0,0},dy={0,0,-1,1};
template<typename T,typename U> inline bool chmin(T& t, const U& u){if(t>u){t=u;return 1;}return 0;}
template<typename T,typename U> inline bool chmax(T& t, const U& u){if(t<u){t=u;return 1;}return 0;}
template<typename T> inline T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<typename T,typename Y> inline T mpow(T a, Y n) {
  T res = 1;
  for(;n;n>>=1) {
    if (n & 1) res = res * a;
    a = a * a;
  }
  return res;
}



signed main(){
  cin.tie(0);ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);
  ll n,m;cin>>n>>m;
  string s;cin>>s;
  VV<int> e(n,V<int>(0));
  V<int> a(n,0),b(n,0);
  rep(i,0,m){
    int x,y;cin>>x>>y;
    x--;y--;
    e[x].pb(y);
    e[y].pb(x);
    if(s[x]=='A'){
      a[y]++;
    }else{
      b[y]++;
    }

    //if(x==y)continue;

    if(s[y]=='A'){
      a[x]++;
    }else{
      b[x]++;
    }
  }

  queue<int> q;
  V<bool> used(n,false);
  rep(i,0,n){
    if(!a[i] || !b[i]){
      q.push(i);
      used[i]=true;
    }
  }

  while(q.size()){
    int now=q.front();
    q.pop();
    if(s[now]=='A'){
      rep(i,0,siz(e[now])){
        a[e[now][i]]--;
      }
    }else{
      rep(i,0,siz(e[now])){
        b[e[now][i]]--;
      }
    }

    rep(i,0,siz(e[now])){
      if(!used[e[now][i]] && (!a[e[now][i]] || !b[e[now][i]])){
        q.push(e[now][i]);
        used[e[now][i]]=true;
      }
    }
  }


  int ans=0;
  rep(i,0,n){
    //cout<<a[i]<<" "<<b[i]<<ENDL;
    if(a[i] && b[i]){
      ans++;
    }
    //assert(a[i]>=0 && b[i]>=0);
  }
  if(ans){
    cout<<"Yes"<<ENDL;
  }else{
    cout<<"No"<<ENDL;
  }
}
//( ・ __ ・ ) KEEP BEING ORGANIZED
//CHECK overflow,vector_size,what to output?
