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
   
   vector<int> a;
   int sum=0;
   a.push_back(0);
   rep(i,n){
      int x;
      cin>>x;
      a.push_back(x);
   }
   a.push_back(0);

   rep(i,n+1){
      sum+=abs(a[i+1]-a[i]);
   }
   
   rep(i,n+1){
      if(i==0) continue;
      cout<<sum+abs(a[i-1]-a[i+1])-(abs(a[i-1]-a[i])+abs(a[i]-a[i+1]))<<endl;
   }
   
   return 0;
}
