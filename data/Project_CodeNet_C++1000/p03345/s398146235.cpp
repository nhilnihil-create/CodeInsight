#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18

using namespace std;

int main(void){
  ll a, b, c, k;
  cin >> a >> b >> c >> k;
  
  if (k % 2){
    cout << b - a << endl;
  }
  else
    cout << a - b << endl;

  return 0;
}
