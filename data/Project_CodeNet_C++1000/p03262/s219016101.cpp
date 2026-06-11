#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

int main() {
  ll N=0,X=0,ans=0;
  cin >> N >> X;
  vector<ll>A(N);
  rep(i,N){
    cin >> A[i];
  }
  vector<ll>s(N);
  rep(i,N){
    s[i] = abs(A[i] - X);
  }
  ans = s[0];
  rep(i,N-1){
    ans = __gcd(ans,s[i+1]);
  }
  cout << ans;
}