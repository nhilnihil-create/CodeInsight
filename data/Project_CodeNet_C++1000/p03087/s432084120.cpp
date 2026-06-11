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
   int n,q;
   cin>>n>>q;
   vector<int> a(n+10);
   string s;
   cin>>s;
   a[0]=0;
   if(s[0]=='A' && s[1]=='C'){
      a[1]=1;
   }
   else {
      a[1]=0;
   }
   for(int i=2;i<=n;i++){
      int x;
      if(s[i-1]=='A' && s[i]=='C'){
         x=1;
      }
      else x=0;
      a[i]=a[i-1]+x;
   }

   rep(i,q){
      int l,r;
      cin>>l>>r;
      cout<<a[r-1]-a[l-1]<<endl;
   }
   
   return 0;
}
