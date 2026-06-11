#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;

const int INF = 1e9;

int main(){
  int n;
  cin >> n;
  
  bool p = false, m = false;
  int ma = -INF, mi = INF;
  int index1 = 0, index2 = 0;
  rep(i,n) {
    int a;
    cin >> a;
    if (a >= 0) p = true;
    else m = true;

    if (ma < a) ma = a, index1 = i+1;
    if (mi > a) mi = a, index2 = i+1;
  }
  
  if (p && !m) {
    cout << n-1 << endl;
    for (int i = 1; i < n; i++) {
      cout << i << " " << i+1 << endl;
    }
  } else if (!p && m) {
    cout << n-1 << endl;
    for (int i = n; i > 1; i--) {
      cout << i << " " << i-1 << endl;
    }
  } else {
    if (abs(ma) > abs(mi)) {
      cout << 2*n-1 << endl;
      for (int i = 1; i <= n; i++) {
        cout << index1 << " " << i << endl;
      }
      for (int i = 1; i < n; i++) {
      cout << i << " " << i+1 << endl;
    }

    } else {
       cout << 2*n-1 << endl;
      for (int i = 1; i <= n; i++) {
        cout << index2 << " " << i << endl;
      }
      for (int i = n; i > 1; i--) {
      cout << i << " " << i-1 << endl;
      }

    }
  }

  return 0;
}