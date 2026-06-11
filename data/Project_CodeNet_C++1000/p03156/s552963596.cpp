#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1000000000000000000

using namespace std;

int main(void){
  ll n, a, b;
  cin >> n >> a >> b;
  
  ll c[3] = {};
  for (int i = 0; i < n; i++){
    ll p;
    cin >> p;
    
    if (p <= a)
      c[0]++;
    else if (p <= b)
      c[1]++;
    else
      c[2]++;
  }

  cout << min(c[0], min(c[1], c[2])) << endl;
  return 0;
}
