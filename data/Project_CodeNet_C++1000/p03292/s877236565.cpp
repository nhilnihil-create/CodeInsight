#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main() {
  ll n = 3;
  vector<ll>A(n);
  rep(i,n){
    cin >> A[i];
  }
  sort(A.begin(), A.end()); //小さい順
  cout << A[2] - A[0];
}