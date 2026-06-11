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
   string s;
   ll k;
   cin>>s>>k;

   ll n=s.size();

   rep(i,min(n,k)){
      if(s[i]!='1'){
         cout<<s[i];
         return 0;
      }
   }
   cout<<1<<endl;
   return 0;
}
