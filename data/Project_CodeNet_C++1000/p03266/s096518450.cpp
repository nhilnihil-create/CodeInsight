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
  int c = 0, d = 0;
  ll ans;
  if (k%2 == 0){
    for(int i = 1; i <= n; i++){
      if (i%k == 0) c++;
      else if (i%k == k/2) d++;
    }
    ans = pow(c, 3) + pow(d, 3);
  }else {
    for (int i = 1; i <= n; i++){
      if (i%k == 0) c++;
    }
    ans = pow(c, 3);
  }
  cout << ans << endl;
}
