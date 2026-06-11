#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define INF (long long)(1e9+7)
#define REP(i,n) for(ll i = 0; i < n; i++)
#define REP1(i,n) for(ll i = 1; i <= n; i++)

int main(void)
{
  int n[6];
  cin >> n[0] >> n[1] >> n[2] >> n[3];
  sort(n, n+4);
  if(n[0] == 1 && n[1] == 4 && n[2] == 7 && n[3] == 9) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
