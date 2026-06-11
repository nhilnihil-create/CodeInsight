#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  int n;
  cin >> n;
  vector<int> arr(n);

  for (int i = 0; i < n; ++i) cin >> arr[i];

  sort(begin(arr), end(arr), greater<int>());
  int a = 0, b = 0;

  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0) a += arr[i];
    else b += arr[i];
  }

  cout << a - b << "\n";

}
