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

   vector<int> a(200010,0);
   ll syurui=0;
   rep(i,n){
      int x;
      cin>>x;
      if(a[x]==0) {
         syurui++;
         a[x]++;
      }
      else{
         a[x]++;
      }
   }
   int p=syurui-k;

   vector<int> b;
   rep(i,200010){
      if(a[i]!=0){
         b.push_back(a[i]);
      }
   }
   sort(b.begin(),b.end());
   int ans=0;
   rep(i,p){
      ans+=b[i];
   }
   cout<<ans;
   return 0;
}
