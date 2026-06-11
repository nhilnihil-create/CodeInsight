//#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
//using namespace atcoder;
#define int long long
   template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
    const int MAX =200005;
const int MOD =1000000007;

signed main(){
 int n;
 cin>>n;
 int x,y,p[n],q[n];
 for(int i=0;i<n;i++){
   cin>>x>>y;
   p[i]=x+y;
   q[i]=x-y;
 }
 for(int i=1;i<n;i++)if(abs(p[i])%2!=abs(p[0])%2){
   cout<<-1<<endl;
   return 0;
 }
 if(p[0]%2==0){
   cout<<32<<endl;
   for(int i=30;i>=0;i--)cout<<(1ll<<i)<<' ';
   cout<<1<<endl;
   for(int j=0;j<n;j++){
   for(int i=30;i>=0;i--){
     if(p[j]>=0){
       p[j]-=(1ll<<i);
       if(q[j]>=0){
         cout<<'R';
         q[j]-=(1ll<<i);
       }else{
         cout<<'U';
         q[j]+=(1ll<<i);
       }
     }else{
       p[j]+=(1ll<<i);
       if(q[j]>=0){
         cout<<'D';
         q[j]-=(1ll<<i);
       }else{
         cout<<'L';
         q[j]+=(1ll<<i);
       }
     }
    
   }
    if(p[j]>=0){
       p[j]-=(1ll<<0);
       if(q[j]>=0){
         cout<<'R';
         q[j]-=(1ll<<0);
       }else{
         cout<<'U';
         q[j]+=(1ll<<0);
       }
     }else{
       p[j]+=(1ll<<0);
       if(q[j]>=0){
         cout<<'D';
         q[j]-=(1ll<<0);
       }else{
         cout<<'L';
         q[j]+=(1ll<<0);
       }
     }
     cout<<endl;
   }

 }else{
   cout<<31<<endl;
   for(int i=30;i>=0;i--)cout<<(1ll<<i)<<' ';
  cout<<endl;
   for(int j=0;j<n;j++){
   for(int i=30;i>=0;i--){
     if(p[j]>=0){
       p[j]-=(1ll<<i);
       if(q[j]>=0){
         cout<<'R';
         q[j]-=(1ll<<i);
       }else{
         cout<<'U';
         q[j]+=(1ll<<i);
       }
     }else{
       p[j]+=(1ll<<i);
       if(q[j]>=0){
         cout<<'D';
         q[j]-=(1ll<<i);
       }else{
         cout<<'L';
         q[j]+=(1ll<<i);
       }
     }
    
   }
  cout<<endl;
   }
 }
}