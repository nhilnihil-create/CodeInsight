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
   int n,k;
   cin>>n>>k;

   long double ans=0;

   for(int i=1;i<=n;i++){
      int x;
      int count=0;
      while(true){
         int a=pow(2,count)*i;
         if(a>=k){
            x=count;
            break;
         }
         count++;
      }

      long double y=(double)pow(2,x);
      y*=n;
      long double z=1/y;
      ans+=z;
      
   }
   cout<<std::setprecision(10)<<ans<<endl;
   
   return 0;
}
