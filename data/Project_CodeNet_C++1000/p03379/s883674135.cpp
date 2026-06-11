#include <bits/stdc++.h>
#include <iomanip>
#include <algorithm>
#define ll long long
#include <unordered_map>
using namespace std;
 
int main() {
  ll N, l, r;
  cin >> N;
  vector<ll> X(N), sortX(N);
  for(ll i = 0; i < N; i++) {
    cin >> X.at(i);
    sortX.at(i) = X.at(i);
  }
  sort(sortX.begin(), sortX.end());
  l = sortX.at(N / 2 - 1);
  r = sortX.at(N / 2);
  for(ll i = 0; i < N; i++) {
    if(X.at(i) <= l) cout << r << endl;
    else cout << l << endl;
  }
}