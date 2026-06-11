#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> P;
typedef vector<vector<int>> Matrix;
static const int INF = 2000000000;


int main(){
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  sort(ALL(a));
  int c = 1;
  int key = a[0];
  vector<int> d;
  for (int i = 1; i < n; i++){
    if (a[i] == key) c++;
    else {
      d.push_back(c);
      c = 1;
      key = a[i];
    }
  }
  d.push_back(c);

  sort(ALL(d));
  int ans = 0;
  if (d.size() > k){
    rep(i, d.size() - k){
      ans += d[i];
    }
  }
  cout << ans << endl;
}