#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int, int>;
typedef vector<int> vi;

int main() {
  int N;
  int d[110];
  cin >> N;
  rep(i, N) cin >> d[i];

  set<int> values;
  rep(i, N) values.insert(d[i]);

  cout << values.size() << endl;

  return 0;
}