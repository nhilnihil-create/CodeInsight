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
struct Data{
  ll a,b,c;
  Data(ll a,ll b,ll c):a(a),b(b),c(c) {}
};
int main(){
  ll d;
  cin>>d;
    d--;
  ll m=d;
  int cnt=0;
  while(d){
    d/=2;
    cnt++;
  }
  ll now=1;
  V<Data> ans;
  if((1<<cnt)-1==m){
  for(int i=0;i<19;i++){
    ans.emplace_back(20-i-1,20-i,0);
   }
   for(int i=0;i<cnt;i++){
       ans.emplace_back(20-i-1,20-i,now);
       now*=2;
   }
 }else{
   for(int i=0;i<19;i++){
    ans.emplace_back(20-i-1,20-i,0);
   }
   for(int i=0;i<cnt-1;i++){
       ans.emplace_back(20-i-1,20-i,now);
       now*=2;
   }
   d=m;
   now=1;
   V<int> t;
   while(d){
     t.push_back(d%2);
     now*=2;
     d/=2;
   }
   now/=2;
   int ind=20;
   reverse(all(t));
    ans.emplace_back(1,ind,now);
   for(int i=1;i<t.size();i++){
     if(t[i]==1){
       ans.emplace_back(1,20-(t.size()-i-1),now+1);
       now+=(1<<(t.size()-i-1));
     }
   }
 }
 cout<<20<<" "<<ans.size()<<"\n";
 for(int i=0;i<ans.size();i++){
  cout<<ans[i].a<<" "<<ans[i].b<<" "<<ans[i].c<<"\n";
 }
}
