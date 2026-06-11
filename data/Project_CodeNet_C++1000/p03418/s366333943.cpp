#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define All(V) V.begin(), V.end()
typedef long long int ll;
typedef pair<int, int> P;
const ll MOD = 1e9+7, INF = 1e9;

int main()
{
  int n, k; cin >> n >> k;
  ll ans = 0;
  if(k == 0){
    cout <<  (ll)n*n << endl;
    system("pause");
    return 0;
  }
  for(int i = 1; i <= n; i++){
    ans += ((n/i) * max(0, i-k)) +  max(0, (n%i)-k+1);
  }//0 1 2 0 1 2
  cout << ans << endl;
  system("pause");
}
