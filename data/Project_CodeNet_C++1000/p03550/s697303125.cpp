#include <bits/stdc++.h>
//#include <atcoder/all>
#define ll long long int
#define MOD 1000000007
#define P pair<ll,ll>
#define INF 1000000000000000000

//using namespace atcoder;
using namespace std;

int main(void){
  ll n, z, w;
  cin >> n >> z >> w;
  vector<ll> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  if (n == 1)
    cout << abs(a[n-1]- w) << endl;
  else
    cout << max(abs(a[n-1]-w), abs(a[n-2]- a[n-1])) << endl;

  return 0;
}
