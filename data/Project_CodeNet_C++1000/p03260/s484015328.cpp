#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
int main() {
  int a, b;
  cin >> a >> b;
  printf((a * b) % 2 == 0 ? "No" : "Yes");
  cout << endl;
}