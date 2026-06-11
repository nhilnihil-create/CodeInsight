#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b(101);
  for (int i = 0; i < n; i++) {
    b[a[i]]++;
  }
  int count = 0;
  for (int j = 0; j < 101; j++) {
    if (b[j] != 0) {
      count++;
    }
  }
  cout << count << endl;
}