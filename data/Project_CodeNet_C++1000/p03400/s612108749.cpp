#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  int n, d, x;
  cin >> n >> d >> x;

  vector<int> arr(n + 1);
  for (int i = 1; i <= n; ++i) cin >> arr[i];

  int count = 0;
  for (int i = 1; i <= n; ++i) {
    int j = 1, day = 0;
    while (day <= d) {
      day = j * arr[i] + 1;
      count++, j++;
    }
  }

  cout << count + x << endl;
}
