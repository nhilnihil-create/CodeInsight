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
   int n;
   cin>>n;
   string s;
   cin>>s;
   int q;
   cin>>q;
   while(q--){
       int k;cin>>k;
       ll d=0,m=0,dm=0,ans=0;//オーバーフロー注意
       for(int i=0;i<n;i++){
            if(i-k>=0){
               if(s[i-k]=='D'){
                   d--;
                   dm-=m;
               }
               if(s[i-k]=='M'){
                   m--;
               }
           }
           if(s[i]=='D')d++;
           if(s[i]=='M'){
               dm+=d;
               m++;
           }
           if(s[i]=='C')ans+=dm;
       }
       cout<<ans<<"\n";
   }
}