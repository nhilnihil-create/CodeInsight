#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
#define INF 1000000000000
#define MOD 1000000007
using ll = long long;



int main(){
  int n,k;
  cin >> n >> k;
  ll l = n/k,l2 = (n+k/2)/k;
  if(k%2!=0){
    cout<<l*l*l<<endl;
  }else{
    cout<<l*l*l+l2*l2*l2<<endl;
  }
  return 0;
}
