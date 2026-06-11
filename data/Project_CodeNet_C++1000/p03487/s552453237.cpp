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
   vector<int> a(100000,0);
   vector<int> b(n);
   int x=0;
   rep(i,n){
      cin>>b[i];
      if(b[i]>100000) x++;
      else a[b[i]]++;
   }
   sort(b.begin(),b.end());
   int ans=0;
   rep(i,n-x){
      if(a[b[i]]!=b[i]){
         if(a[b[i]]>b[i]){
            ans+=a[b[i]]-b[i];
            a[b[i]]=b[i];
         }
         else{
            ans+=a[b[i]];
            a[b[i]]=0;
         }
      }
   }
   ans+=x;
   cout<<ans;
   return 0;
}
