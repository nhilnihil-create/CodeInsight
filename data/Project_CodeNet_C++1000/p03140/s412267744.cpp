#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
  ll N;
  cin >> N;
  string A,B,C;
  cin >> A >> B >> C;
  ll ans=0;
  for (ll i = 0; i < N; ++i) {
  	ll op;
    if (A[i]==B[i] && B[i]==C[i]) op = 0;
    else if (A[i]==B[i] && B[i]!=C[i]) op = 1;
    else if (A[i]!=B[i] && B[i]==C[i]) op = 1;
    else if (A[i]!=B[i] && A[i]==C[i]) op = 1;
    else op = 2;
    ans += op;
  }
  cout << ans << endl;
  return 0;
}