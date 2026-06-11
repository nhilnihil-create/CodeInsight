#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); i++)
#define MOD 1000000007
#define INF 1e9
#define All(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;

int main(){
  int N;
  ll x;
  cin >> N >> x;
  vector<ll> a(N);
  REP(i, N)cin >> a[i];
  sort(All(a));
  ll ans = 0;
  for (int i = 0; i < N;i++){
    x -= a[i];
    if(x<0){
      cout << ans << endl;
      return 0;
    }
    ans++;
  }
  if(x>0)
    ans--;
  cout << ans << endl;

  return 0;
}
