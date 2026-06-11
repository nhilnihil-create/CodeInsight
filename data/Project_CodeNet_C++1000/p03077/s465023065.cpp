#include <bits/stdc++.h>
using namespace std;

#define ll long long

void chmin(ll&a, ll b) {
  if (a > b) a = b;
}

int main() {
  ll N;
  cin >> N;
  
  ll minimum = 1000000000000000;
  for (int i = 0; i < 5; i++) {
    ll x;
    cin >> x;
    chmin(minimum, x);
  }

  
  cout << (N+minimum-1) / minimum + 4 << endl;
  
}