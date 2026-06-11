#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
  int n;
  cin >> n;
  vector<int> o(100010), e(100010);
  rep(i,n) {
    int v; cin >> v;
    if (i%2 == 1) o[v]++;
    else e[v]++;
  }
  int i = max_element(e.begin(),e.end()) - e.begin();
  int j = max_element(o.begin(), o.end()) - o.begin();
  if (i != j) {
    cout << n-e[i]-o[j] << endl;
  } else {
    sort(e.rbegin(),e.rend());
    sort(o.rbegin(),o.rend());
    int an = min(n-e[0]-o[1],n-e[1]-o[0]);
    cout << an << endl;
  }
  return 0;
}