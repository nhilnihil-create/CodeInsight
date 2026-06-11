#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))
const ll INF = 1001001001;
const ll MOD = 1e9 + 7;

int main(){
  int n, T;
  cin >> n >> T;
  int ans = INF;
  rep(i, n){
    int t, c;
    cin >> c >> t;
    if(t <= T){
      ans = min(ans, c);
    }
  }
  if(ans == INF){
    cout << "TLE" << endl;
    return 0;
  }
  cout << ans << endl;
}