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

   if(n==1 && m==1) cout<<1;
   else if(n==1) cout<<max(m-2,0);
   else if(m==1) cout<<max(n-2,0);
   else cout<<(ll)(n-2)*(m-2);
   
   
   
   return 0;
}
