#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  
  int count = 0;
  
  for (int i = 0; i <= N; ++i) {
    for (int j = 0; j <= N; ++j) {
	  int total = 4 * i + 7 * j;
      if (total == N) ++count;
    }
  }
  if (count > 0) cout << "Yes" << endl;
  else cout << "No" << endl;
}