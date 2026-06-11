#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
void Erato(vector<int> &A, int mx) {
  int a[100000];
  for (int i = 2; i <= mx; i++) {
    if (a[i] != 0) continue;
    for (int j = 2; j * i <= mx; j++) {
      a[i * j] = 1;
    }
  }
  for (int i = 2; i <= mx; i++) {
    if (a[i] == 0) A.push_back(i);
  }
}
int main() {
  int N;
  cin >> N;
  vector<int> Sosuu(0);
  Erato(Sosuu, 55555);
  int sum = 0, id = 0;
  for (int i = 0;; i++) {
    if (id >= N) break;
    if ((Sosuu[i] % 5) != 1) continue;
    cout << Sosuu[i];
    if (id != N - 1) cout << " ";
    id++;
  }
  cout << endl;
}