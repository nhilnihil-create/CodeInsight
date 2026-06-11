#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  ll n,d,x;
  cin >> n >> d >> x;
  
  vector<ll> A(n);
  ll eat = 0;
  rep(i,n){
    cin >> A[i];
    rep(j,d){
      if(j*A[i]+1 <= d) eat++;
    }
  }
  ll ans = eat + x;
  cout << ans << endl;
}