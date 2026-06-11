#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18

using namespace std;

int main(void){
  ll n;
  cin >> n;
  
  map<ll, ll> m;
  for (int i = 0; i < n; i++){
    ll d;
    cin >> d;
    
    m[d]++;
  }
  ll M;
  cin >> M;
  
  
  int ok = 1;
  for (int i = 0; i < M; i++){
    ll t;
    cin >> t;
    if (m[t] == 0)
      ok = 0;
    else
      m[t]--;
  }
  
  if(ok)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
    

  return 0;
}
