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
   
   vector<int> x(n);

   rep(i,n){
      cin>>x[i];
   }
   vector<int> y=x;
   sort(x.begin(),x.end());

   int l=n/2-1;
   int r=n/2;

   rep(i,n){
      if(y[i]<=x[l]) cout<<x[r]<<endl;
      else cout<<x[l]<<endl;
   }
   return 0;
}
