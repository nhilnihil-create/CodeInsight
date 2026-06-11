#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int mean = 0;
  vector <int> vec(n);
  for (int i = 0; i < n; i++) {
    cin >> vec.at(i);
    mean += vec.at(i);
  }
  int tmp = 100*n;
  int ans;
  for (int i = 0; i < n; i++) {
    int a = vec.at(i)*n;
    int b = mean;
    if (a < b) {
      int num = a;
      a = b;
      b = num;
    }
    if (a-b < tmp) {
      tmp = a-b;
      ans = i;
    }
  }
  cout << ans << endl;
}