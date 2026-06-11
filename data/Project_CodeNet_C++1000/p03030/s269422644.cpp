#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using ll = long long int;
using vec = vector<int>;
using P = pair<int,int>;
using PS = pair<string,P>;
const int INF = 1e9+7;

int main() {
  int n; cin >> n;
  vector<PS> v(n);
  rep(i,n) {
    int p;
    string s;
    cin >> s >> p;
    v[i] = PS(s, P(100-p, i));
  }

  sort(all(v));

  rep(i,n) {
    cout << v[i].second.second+1 << endl;
  }
}
