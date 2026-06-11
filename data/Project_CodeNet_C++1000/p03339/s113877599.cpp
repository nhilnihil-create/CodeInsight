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
   string s;
   cin>>s;

   vector<int> l(n,0);
   vector<int> r(n,0);

   rep(i,n){
      if(i==0) continue;
      else if(s[i]=='E') r[0]++;
   }
   rep(i,n){
      if(i==0) continue;
      if(s[i-1]=='W') l[i]=l[i-1]+1;
      else{
         l[i]=l[i-1];
      }
      if(s[i]=='E') r[i]=r[i-1]-1;
      else{
         r[i]=r[i-1];
      } 
   }
   int ans=INFINITY;
   rep(i,n){
      ans=min(ans,r[i]+l[i]);
   }
   cout<<ans;
   return 0;
}
