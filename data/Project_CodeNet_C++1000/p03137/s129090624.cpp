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
  int n,m;
  cin>>n>>m;
  vector<int> x(m,0);
  vector<int> b(m-1,0);
  ll ans=0;

  rep(i,m){
     cin>>x[i];
  }
  sort(x.begin(),x.end());

  if(n>=m){
     cout<<0;
     return 0;
  }

  rep(i,m-1){
     b.push_back(x[i+1]-x[i]);
     ans+=x[i+1]-x[i];
  }
  sort(b.begin(),b.end(),greater<int>());

  rep(i,n-1){
     ans-=b[i];
  }
  cout<<ans;





return 0;
}
