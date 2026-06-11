#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair <int, int>;
const double PI = acos(-1);



int main() {
  int N, M;
  cin >> N >> M;

  vector<P> vs(M);
  rep(i, M){
    int a, b;
    cin >> a >> b;
    vs.at(i) = make_pair(b, a);
  }

  sort(vs.begin(), vs.end());

  int cur = 0;
  int ans = 0;

  rep(i, M){
    if(cur <= vs.at(i).second){
      cur = vs.at(i).first;
      ans++;
    }
  }

  cout << ans << endl;
}
