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
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n){
    cin >> a[i];
    a[i] -= (i + 1);
  }
  vector<int> d = a;
  sort(ALL(d));
  int b = d[n/2];

  ll ans = 0;
  rep(i, n){
    ans += abs(a[i] - b);
  }
  cout << ans << endl;
}

