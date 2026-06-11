#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> a(N), b(200);
  for (int i = 0; i < N; i++){
    cin >> a[i];
  }
  sort (a.begin(), a.end());
  int ans = 0;
  for (int i = 0; i < N; i++){
    if (b[a[i]] == 1) continue;
    b[a[i]] = 1;
    ans++;
  }
  cout << ans << endl;
}