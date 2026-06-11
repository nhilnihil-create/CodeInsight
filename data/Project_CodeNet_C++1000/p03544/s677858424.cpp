#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main() {
  ll N;
  cin >> N;
  vector<ll>A(88);
  A[0] = 2; A[1] = 1;
  rep(i,86){
    A[i+2] = A[i+1] + A[i];
  }
  cout << A[N];
}