#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main() {
  ll N = 3;
  vector<ll>A(N);
  rep(i,N){
    cin >> A[i];
  }
  sort(A.begin(),A.end(),greater<ll>());
  cout << A[0]*10 + A[1] + A[2];
}