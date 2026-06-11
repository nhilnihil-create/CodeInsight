#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  ll n,m,d; cin>>n>>m>>d;

  double result=0.0;
  if(d==0) result = (double)1/n;
  else result = (double)2*(n-d)/n/n;
  result *= (m-1);

  cout<<fixed<<setprecision(12)<<result;

  return 0;
}