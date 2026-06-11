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
const ll mod=1000000007;
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
int main(){
   int h,w,n;
   cin>>h>>w>>n;
   int ny,nx;
   cin>>ny>>nx;
   string s,t;
   cin>>s>>t;
   int l=0,r=w+1;
   if(s[n-1]=='L')l++;
   if(s[n-1]=='R')r--;
   bool able=true;
   for(int i=n-2;i>=0;i--){
       if(t[i]=='L'&&r<=w)r++;
       if(t[i]=='R'&&l>0)l--;
       if(s[i]=='L')l++;
       if(s[i]=='R')r--;
       if(abs(l-r)<=1)able=false;
   }
   if(l>=nx||nx>=r)able=false;
   int u=0,d=h+1;
   if(s[n-1]=='U')u++;
   if(s[n-1]=='D')d--;
   for(int i=n-2;i>=0;i--){
       if(t[i]=='U'&&d<=h)d++;
       if(t[i]=='D'&&u>0)u--;
       if(s[i]=='U')u++;
       if(s[i]=='D')d--;
       if(abs(u-d)<=1)able=false;
   }
   if(u>=ny||ny>=d)able=false;
   if(able)cout<<"YES"<<"\n";
   else cout<<"NO"<<"\n";
}
