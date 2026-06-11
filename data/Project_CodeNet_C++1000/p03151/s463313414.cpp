#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18

using namespace std;

int main(void){
  ll n;
  cin >> n;
  
  vector<ll> a(n), b(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  for (int i = 0; i < n; i++){
    cin >> b[i];
  }

  ll upnum = 0, up = 0;
  for (int i = 0; i < n; i++){
    if (a[i] < b[i]){
      up += b[i] - a[i];
      upnum++;
    }
  }
  vector<ll> amari(0);
  for (int i = 0; i < n; i++){
    if (a[i] > b[i]){
      amari.emplace_back(a[i] - b[i]);
    }
  }
  sort(amari.begin(), amari.end());

  
  for (int i = 0; i < amari.size(); i++){
    if (up <= 0)
      break;
    upnum++;
    up -= amari[amari.size()-i-1];
  }

  if (up <= 0)
    cout << upnum << endl;
  else
    cout << -1 << endl;
  
  
  
  
  
  
  

  return 0;
}
