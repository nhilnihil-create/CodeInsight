#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, A, B;
  cin >> N >> A >> B;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
	cin >> a.at(i);
  }
  sort(a.begin(),a.end());
  int j = 0, k = N - 1;
  while(1) {
	if (a.at(j) > A) {
      break;
    }
    j++;
  }
  while(1) {
	if (a.at(k) < B + 1) {
      break;
    }
    k--;
  }
  cout << min(min(j, k + 1 - j), N - k - 1) << endl;
}