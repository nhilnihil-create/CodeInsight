#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

int main() {
  int N;
  cin >> N;
  vector<int> vec(N);
  for (int i; i < N; i++) cin >> vec[i];
  sort(vec.begin(), vec.end());
  
  int ans = 1;
  for (int i; i < N-1; i++) {
    if (vec[i] != vec[i+1]) ans += 1;
  }
  cout << ans << endl;
}