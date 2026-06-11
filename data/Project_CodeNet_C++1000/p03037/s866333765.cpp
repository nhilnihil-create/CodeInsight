#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define PI acos(-1)
typedef  long long ll;
ll gcd(ll x,ll y){
   if(y==0) return x;
   else return gcd(y,x%y);
}
ll lcm(ll x,ll y){
   return x/gcd(x,y)*y;
}

int main(){
   int n,m;
   cin>>n>>m;
   int l=1;
   int r=n;
   rep(i,m){
      int a,b;
      cin>>a>>b;
      if(l<a){
         l=a;
      }
      if(b<r){
         r=b;
      }
   }
   int ans=r-l+1;

   if(ans<0) ans=0;

   cout<<ans;
   return 0;
}
