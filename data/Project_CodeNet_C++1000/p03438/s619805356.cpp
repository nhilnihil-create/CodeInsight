#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
int main() {
  int n;cin >> n;vector<ll> A(n), B(n);ll suma = 0, sumb = 0;
  rep(i,n) cin >> A[i];
  rep(i,n)  cin >> B[i];
  rep(i,n){
    if(A[i] > B[i]) suma += A[i] - B[i];
    if(B[i] > A[i]) sumb += (B[i] - A[i])/2;
  }
  if(sumb >= suma) cout << "Yes" << endl;
  else cout << "No" <<endl;
}