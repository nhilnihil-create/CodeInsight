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
int main(){
 ll n;
 cin>>n;
 if(n==3){
     cout<<2<<" "<<3<<" "<<25<<"\n";
     return 0;
 }
 if(n==4){
     cout<<2<<" "<<3<<" "<<4<<" "<<9<<"\n";
     return 0;
 }
 V<ll> ans,two1,two2,th;
 ll t=1;
 while(t*2<=30000){
     if(t%3==1)two1.push_back(t*2);
     else if(t%3==2)two2.push_back(t*2);
     t++;
 }
 t=1;
 while(t*3<=30000){
     if(t%2)th.push_back(t*3);
     t++;
 }
 ll m=n;
 for(int i=0;i<min(two1.size(),two2.size());i++){
     if(m<=3)break;
     m-=2;
     ans.push_back(two1[i]);
     ans.push_back(two2[i]);
 }
 for(int i=0;i<th.size();i+=2){
     if(m<2)break;
     m-=2;
    ans.push_back(th[i]);
    ans.push_back(th[i+1]);
 }
  t=1;
 while(m--){
     if(t>5000)break;
     ans.push_back(t*6);
     t++;
 }
 for(int i=0;i<n;i++){
  cout<<ans[i]<<" ";
 }
 cout<<"\n";
}