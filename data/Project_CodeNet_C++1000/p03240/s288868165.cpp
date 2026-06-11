#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <numeric>
#include <cmath>

#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
using P = pair<ll, ll>;

template<class T> inline bool chmin(T& a,T b) {if (a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a,T b) {if (a < b) {a = b; return true;} return false;}

const ll MOD = 1000000007;
const int INF = 1<<30;
//const ll INF = (ll)1e18 + 1;

int main(){
  int N; cin >> N;
  vector<int> x(N), y(N), h(N);
  rep(i, N){
    cin >> x[i] >> y[i] >> h[i];
  }
  for (int Cx = 0; Cx <= 100; ++Cx){
    for (int Cy = 0; Cy <= 100; ++Cy){
      int H = 0;
      for (int n = 0; n < N; ++n){
        if (h[n] > 0) {
          H = h[n] + abs(x[n] - Cx) + abs(y[n] - Cy);
          break;
        }
      }
      bool flag = true;
      for (int n = 0; n < N; ++n){
        int h_check = max(H - abs(x[n] - Cx) - abs(y[n] - Cy), 0);
        if (h_check != h[n]) flag = false;
      }
      if (flag){
        cout << Cx << " " << Cy << " " << H << endl;
        return 0;
      }
    }
  }
}
