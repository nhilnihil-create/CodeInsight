#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main(){
  ll n,k;
  cin>>n>>k;
  
  ll x=n/k;
  ll y=(2*n+k)/(2*k);
  
  if(k%2==1){
    cout<<x*x*x<<endl;
  }
  else{
    cout<<x*x*x+y*y*y<<endl;
  }
  
  return 0;
}