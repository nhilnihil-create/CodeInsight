#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m1(x) memset(x,-1,sizeof(x))
const int INF = 1001001001;
const ll MOD = 1e9 + 7;
const double PI = 3.14159265358979;

int main(){
  int n, k;
  int x[110000];
  cin >> n >> k;
  rep(i, n) cin >> x[i];
  int ans = 1e9;
  for(int i = 0; i < n - k + 1; i++){
    if(x[i + k - 1] <= 0) ans = min(ans, -x[i]);
    else if(x[i] >= 0) ans = min(ans, x[i + k - 1]);
    else ans = min(ans, x[i+k-1] - x[i] + min(x[i+k-1], -x[i]));
  }
  cout << ans << endl;
}