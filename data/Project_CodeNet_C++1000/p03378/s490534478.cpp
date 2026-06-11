#include <bits/stdc++.h>
//#include <atcoder/all>
#define ll long long int
#define MOD 1000000007
#define P pair<ll,ll>
#define INF 1000000000000000000

//using namespace atcoder;
using namespace std;

int main(void){
  ll n, m, x;
  cin >> n >> m >> x;
  
  vector<ll> a(m);
  ll t = 0;
  for (int i = 0; i < m; i++){
    cin >> a[i];
    if (a[i] < x)
      t++;
  }

  cout << min(t, m - t) << endl;
  

  return 0;
}
