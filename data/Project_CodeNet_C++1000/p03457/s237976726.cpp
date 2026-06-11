// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

/*
 * x+y>(t - t_1)の場合には不可
 * x+yと(t-t_1)の偶奇が一致していない場合は不可
 */
int main() {
  int n; cin >> n;
  vector<int> T(n), X(n), Y(n);
  loop(i,0,n) cin >> T[i] >> X[i] >> Y[i];
  int prev_t = 0, prev_x = 0, prev_y = 0;
  loop(i,0,n) {
    int t = T[i] - prev_t;
    int x = abs(X[i]-prev_x);
    int y = abs(Y[i]-prev_y);
    if (x+y > t) {
      cout << "No" << endl;
      return 0;
    }
    
    if ((x+y)%2 != t%2) {
      cout << "No" << endl;
      return 0;
    }
    
    prev_t = T[i];
    prev_x = X[i];
    prev_y = Y[i];
  }
  cout << "Yes" << endl;
  return 0;
}
