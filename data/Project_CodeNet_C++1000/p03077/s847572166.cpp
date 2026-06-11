#include <bits/stdc++.h>
using namespace std;
using pp=pair<int,int>;
using ll=long long;

int main() {
  ll N;
  cin >> N;
  vector<ll> V(5);
  for (ll i=0; i<5; i++) {
    cin >> V[i];
  }
  ll S=0;
  
  ll Ve=V[0];
  for (ll i=1; i<5; i++) {
    if (V[i]<Ve) {
      Ve=V[i];
    }
  }

  cout << (N-1)/Ve+5 << endl;
  
}