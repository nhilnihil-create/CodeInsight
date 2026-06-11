#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  int n;
  cin >> n;
  vector < int > a;

  if (n == 3) {
    cout << "2 5 63\n";
    return 0;
  }

  int sum = 0;
  for (int i = 1; i <= 30000; i++) {
    if (i % 2 == 0 || i % 3 == 0) {
      a.push_back (i);
      sum += i;
    }
    if (a.size() == n) break;
  }

  int need = (6 - sum % 6) % 6;
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] + need <= 30000 && ((a[i] + need) % 2 == 0 || (a[i] + need) % 3 == 0)) {
      a[i] += need;
      break;
    }
  }

  for (auto i : a) cout << i << " ";
  cout << '\n';
}
