#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); i++)
#define MOD 1000000007
#define INF 1e9
#define All(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;

int main(){
  int n, d, x;
  cin >> n >> d >> x;
  vector<int> a(n);
  REP(i, n) cin >> a[i];
  ll ans = 0;
  for (int i = 0; i < n;i++){
    int cnt = 0;
    while (1+cnt*a[i]<=d){
      cnt++;
    }
    //cout << cnt << endl;
    ans += cnt;
  }
  cout << ans + x << endl;

  return 0;
}
