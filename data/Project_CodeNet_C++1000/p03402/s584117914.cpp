#include <bits/stdc++.h>
//#include <atcoder/all>
#define ll long long int
#define MOD 1000000007
#define P pair<ll,ll>
#define INF 1000000000000000000

//using namespace atcoder;
using namespace std;

int main(void){
  ll a, b;
  cin >> a >> b;
  
  cout << 100 << " " << 100 << endl;

  vector<string> ss(100, "");
  for (ll i = 0; i < 100; i++){
    for (ll j = 0; j < 100; j++){
      ss[i].push_back(i < 50 ? '#' : '.');
    }
  }

  ll x = 1, y = 1;
  for (ll i = 0; i < a-1; i++){
    ss[x][y] = '.';
    if (y == 99){
      x += 2;
      y = 1;
    }
    else {
      y += 2;
    }
  }

  x = 51; 
  y = 1;
  for (ll i = 0; i < b-1; i++){
    ss[x][y] = '#';
    if (y == 99){
      x += 2;
      y = 1;
    }
    else {
      y += 2;
    }
  }

  for (ll i = 0; i < 100; i++){
    cout << ss[i] << endl;
  }


  return 0;
}
