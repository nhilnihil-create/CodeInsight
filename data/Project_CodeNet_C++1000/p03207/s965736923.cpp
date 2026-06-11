#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,-1,sizeof(x))
const int INF = 1000000001;

int main(){
  int n;
  cin >> n;
  int p[10];
  rep(i, n) cin >> p[i];
  sort(p, p + n);
  int ans = 0;
  rep(i, n-1) ans += p[i];
  ans += p[n-1]/2;
  cout << ans << endl;
}