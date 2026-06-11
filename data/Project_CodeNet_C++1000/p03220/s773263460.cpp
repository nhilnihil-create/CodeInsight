#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,-1,sizeof(x))
const int INF = 1000000001;

int main(){
  int n, t, a;
  cin >> n >> t >> a;
  double m = INF;
  int ans = -1;
  rep(i, n){
    int h;
    cin >> h;
    double temp = t - 0.006 * h;
    double d = abs(a - temp);
    if(d < m){
      ans = i;
      m = d;
    }
  }
  cout << ans+1 << endl;
}