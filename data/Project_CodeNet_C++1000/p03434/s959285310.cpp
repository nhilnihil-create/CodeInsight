#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
using ll = long long;

int main() {
  int n; cin >> n;
  std::vector<int> v(n);
  rep(i,n) cin >> v.at(i);
  sort(v.begin(), v.end(), greater<int>());

  int Alice = 0, Bob = 0;
  rep(i,n) {
    if (i % 2 == 0) Alice += v.at(i);
    else Bob += v.at(i);
  }
  cout << Alice - Bob << endl;
}
