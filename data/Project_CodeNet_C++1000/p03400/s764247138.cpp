#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
const long long INF = 1ll << 60;



int main() {
  int n, d, x; cin >> n >> d >> x;
  vector<int> a(n);
  rep(i,n){
    cin >> a[i];
  }
  int tabeta = 0;
  rep(i,n){
    tabeta++;
    for(int j = 1; j * a[i] + 1 <= d; j++){
      tabeta++;
    }
  }

  int ans = tabeta + x;
  cout << ans << endl;

	return 0;
}

