#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> l(n);
  rep(i,n) cin >> l[i];

  int sum = accumulate(l.begin(), l.end(), 0);
  int maxi = *max_element(l.begin(), l.end());

  cout << ((sum - maxi > maxi) ? "Yes" : "No") << endl;
  return 0;
}