#include<bits/stdc++.h>
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

using namespace std;


int main(){
   ll n,a,b,c,d,e;
   cin>>n>>a>>b>>c>>d>>e;
   ll x=min({a,b,c,d,e});

   cout<<ll(ceil(double(n)/x)+4);

return 0;
}

