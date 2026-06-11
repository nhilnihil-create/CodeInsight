#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  vector<int> arr(3);
  for (int i = 0; i < 3; ++i) cin >> arr[i];
  sort(begin(arr), end(arr));

  int k; cin >> k;
  cout << arr[0] + arr[1] + (arr[2] << k) << "\n";
}
