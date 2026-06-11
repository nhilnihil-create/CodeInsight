#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
template<class T> using V=vector<T>; 
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
//const ll mod=998244353;
const ll mod=1000000007;
ll GCD(ll a,ll b) {return b ? GCD(b,a%b):a;}
ll LCM(ll c,ll d){return c/GCD(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
bool solve(){
  ll a,b,c,d;
  cin>>a>>b>>c>>d;
  if(a<b){
    return false;
  }
  if(d<b){
    return false;
  }
  if(b<=c+1){
    return true;
  }
  ll g=GCD(b,d);
  //gで割ってa%gあまり数でb未満になる最大の数
  ll ch=(b-a%g+g-1)/g*g-(g-a%g);
  return ch<=c;
}
int main(){
  int t;
  cin>>t;
  while(t--){
    cout<<(solve()?"Yes":"No")<<"\n";
  }
}