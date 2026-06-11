#include <bits/stdc++.h>
//#include <atcoder/all>
#define ll long long int
#define MOD 1000000007
#define P pair<ll,ll>
#define INF 1000000000000000000

//using namespace atcoder;
using namespace std;

int main(void){
  ll n, x;
  cin >> n >> x;
  
  ll sum = 0;
  ll m = INF;
  for (int i = 0; i < n; i++){
    ll a;
    cin >> a;
    
    m = min(m, a);
    sum += a;
  }

  cout << n + (x - sum) / m << endl;

  return 0;
}
