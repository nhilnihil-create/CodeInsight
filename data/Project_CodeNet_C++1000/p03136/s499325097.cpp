#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  int sum = 0;
  for(int i=0; i<n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  sort(a.rbegin(), a.rend());
  if(sum-a[0] > a[0]) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}