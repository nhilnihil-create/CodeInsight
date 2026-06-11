#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;

const int N = 100010;

signed main() {
  int n;
  cin >> n;

  vector<int> a(n);
  vector<int> odd(N), even(N);
  int odd_max = 0, oddv = 0;
  int even_max = 0, evenv = 0;
  rep(i,n) {
    cin >> a[i];
    if(i % 2 == 0) {
      even[a[i]]++;
      if(even[a[i]] > even_max) {
        even_max = even[a[i]];
        evenv = a[i];
      }
    }
    else {
      odd[a[i]]++;
      if(odd[a[i]] > odd_max) {
        odd_max = odd[a[i]];
        oddv = a[i];
      }
    }
  }

  int answer = n + 1;
  // SET EVEN
  for (int i = 0; i < N; i++) {
    if(i == evenv) continue;

    int tmp = n - even_max - odd[i];
    answer = min(answer, tmp);
  }
  // SET ODD
  for (int i = 0; i < N; i++) {
    if(i == oddv) continue;

    int tmp = n - odd_max - even[i];
    answer = min(answer, tmp);
  }

  cout << answer << endl;

  return 0;
}

