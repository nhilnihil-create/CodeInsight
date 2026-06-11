#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18
#define PI 3.14159265358979

using namespace std;

int main(void){
  ll n, k;
  cin >> n >> k;
  
  ll res = 0;

  ll t = n / k;
  res +=  t * t * t;
  if (k % 2 == 0){
    if (n % k >= k/2)
      res += (t + 1) * (t + 1) * (t + 1);
    else
      res += t * t * t;
  }

  cout << res << endl;

  return 0;
}
