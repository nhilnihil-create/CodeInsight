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
   int n;
   cin>>n;
   vector<int> h(n+10,0);
   vector<int> a(n+10,0);

   rep(i,n){
      int x;
      cin>>x;
      h[i]=x;
   }

   ll ans=0;

   bool f=true;
   while(f){
      int l=-1;
      int r=-1;
      rep(i,n){
         if(a[i]!=h[i] && l==-1){
            l=i;
            for(int j=i+1;j<n;j++){
               if(a[j]==h[j] && r==-1){
                  r=j-1;
                  break;
               }
            }
         }
         if(r!=-1) break;
      }
      if(l==-1 && r==-1) {
         f=false;
         break;
      }
      else if(l!=-1 && r==-1) r=n-1;
      for(int i=l;i<=r;i++){
            a[i]++;
      }
      ans++;
   }
   cout<<ans;
   return 0;
}
