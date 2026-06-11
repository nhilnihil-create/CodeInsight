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
  vector<int> a(n+2);
  a[0] = 0;
  a[n+1] = 0;
  for (int i = 1; i <= n; i++) cin >> a[i];

  vector<int> l(n+1), r(n+1);
  l[0] = abs(a[1]);
  r[n] = abs(a[n]);
  for (int i = 1; i <= n; i++){
    l[i] = l[i-1] + abs(a[i+1] - a[i]);
  }
  for (int i = n-1; i >= 0; i--){
    r[i] = r[i+1] + abs(a[i+1] - a[i]);
  }
  for (int i = 1; i <= n; i++){
    if (i == 1) cout << abs(a[2]) + r[2] << endl;
    else if (i == n) cout << l[n-2] + abs(a[n-1]) << endl;
    else cout << l[i-2] + abs(a[i+1] - a[i-1]) + r[i+1] << endl;
  }
}
