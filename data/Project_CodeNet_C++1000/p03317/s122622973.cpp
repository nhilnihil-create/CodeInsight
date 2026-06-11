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
   vector<int> a(n);
   rep(i,n){
      cin>>a[i];
   }
   int ans=0;
   sort(a.begin(),a.end());
   int c=0;

   while(1){
      for(int i=c;i<c+k;i++){
         a[i]=1;
         if(i==n-1) break;
      }
      c=c+k-1;
      ans++;
      if(c>=n-1) break;
   }
   cout<<ans;
   return 0;
}
