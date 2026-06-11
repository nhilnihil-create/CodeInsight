#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int n, m;
  cin >> n >> m;
  vector<P> ab(m);
  rep(i, m){
    int a, b;
    cin >> a >> b;
    ab[i] = make_pair(b, a);
  }
  sort(ab.begin(), ab.end());
  int ans = 1, end = ab[0].first;
  rep(i, m){
    if (end <= ab[i].second){
      ans++;
      end = ab[i].first;
    }
  }
  cout << ans << endl;
  return 0;
}
