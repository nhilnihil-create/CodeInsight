#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define All(V) V.begin(), V.end()
typedef long long int ll;
typedef pair<int, int> P;
const ll MOD = 1e9+7, INF = 1e9;

int main()
{
  int a, b, ans = 0; cin >> a >> b;
  if(a > 1 && b >= a) ans = a;
  else if(a == 1) ans = 1;
  else ans = a-1;
  cout << ans << endl;
  system("pause");
}
