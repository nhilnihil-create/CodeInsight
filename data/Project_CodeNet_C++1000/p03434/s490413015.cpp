#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n, alice=0, bob=0;
  cin >> n;
  vector<int> a(n);
  rep(i, n)
  {
    cin >> a.at(i);
  }
  sort(a.rbegin(), a.rend());

  rep(i, n)
  {
    if(i%2 == 0)
      alice += a.at(i);
    else
      bob += a.at(i);
  }

  cout << alice-bob << endl;
}
