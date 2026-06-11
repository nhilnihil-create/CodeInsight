#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n,k;
  cin >> n >> k;
  ll p=n/k;
  ll q=0;
  if(k%2==0){
    ll p=k/2;
    while(p<=n){
      p+=k;
      q++;
    }
  }
  ll ans=q*q*q+p*p*p;
  cout << ans;
}
