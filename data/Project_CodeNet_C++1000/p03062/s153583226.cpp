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
  int n;
  cin >> n;
  ll a[100000];
  ll m = INF;
  ll cnt = 0;
  ll ans = 0;
  rep(i, n){
    cin >> a[i];
    m = min(abs(a[i]), m);
    if(a[i] < 0) cnt++;
    ans += abs(a[i]);
  }
  if(cnt % 2) cout << ans - 2*m <<endl;
  else cout << ans <<endl;
}