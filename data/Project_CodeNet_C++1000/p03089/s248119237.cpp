#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18
#define PI 3.14159265358979

using namespace std;

int main(void){
  ll n;
  cin >> n;
  
  vector<ll> b(n);
  for (int i = 0; i < n; i++){
    cin >> b[i];
  }

  int ok = 1;
  for (int i = 0; i < n; i++){
    if (i + 1 < b[i])
      ok = 0;
  }
  if (ok){
    vector<ll> c(n);
    vector<ll> res(n);
    for (int i = 0; i < n; i++){
      c[i] = b[i];
    }
    for (int i = 0; i < n; i++){
      int id = 0;
      for (int j = 0; j < n - i; j++){
        if (c[j] == j + 1){
          id = j;
        }
      }
      res[n - i - 1] = id + 1;
      for (int j = id; j < n - i - 1; j++){
        c[j] = c[j + 1];
      }
    }
    for (int i = 0; i < n; i++){
      cout << res[i] << endl;
    }
  } else {
    cout << -1 << endl;
  }

  return 0;
}
