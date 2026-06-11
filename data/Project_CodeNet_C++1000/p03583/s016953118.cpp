#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
  ll n;
  cin >> n;
  for (ll h = 1; h <= 3500; h++)
  {
    for (ll i = 1; i <= 3500; i++)
    {
      if (4*h*i-n*h-n*i>0 && (n*h*i)%(4*h*i-n*h-n*i)==0) {
        ll j = (n*h*i)/(4*h*i-n*h-n*i);
        cout << h << " " << i << " " << j << endl;
        return 0;
      }
    }
    
  }
  
    return 0;
}