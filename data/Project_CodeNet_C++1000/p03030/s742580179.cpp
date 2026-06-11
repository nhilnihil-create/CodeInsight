#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  vector<tuple<string, int, int>> dic;
  for (int i = 1; i <= n; i++) {
    string s;
    int p;
    cin >> s >> p;
    p *= -1;
    dic.push_back(tie(s, p, i));
  }
  sort(all(dic));
  for (int i = 0; i < n; i++) {
    cout << get<2>(dic[i]) << endl;
  }
}
