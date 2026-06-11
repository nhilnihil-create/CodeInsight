#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N,A,B;
  cin >> N >> A >> B;
  int P[N];
  int one = 0;
  int two = 0;
  int three = 0;
  for (int i = 0; i < N; i++) {
    cin >> P[i];
    if (P[i] <= A) {
      one++;
    } else if (P[i] >= B+1) {
      three++;
    } else {
      two++;
    }
  }
  cout << min({one,two,three}) << endl;
  return 0;
}