#include <bits/stdc++.h>
//#include <atcoder/all>
#define ll long long int
#define MOD 1000000007
#define P pair<ll,ll>
#define INF 1000000000000000000

//using namespace atcoder;
using namespace std;

int main(void){
  ll n;
  cin >> n;
  
  map<string, ll> t;
  for (int i = 0; i < n; i++){
    string s;
    cin >> s;
    
    t[s]++;
  }

  ll m;
  cin >> m;
  for (int i = 0; i < m; i++){
    string s;
    cin >> s;
    
    t[s]--;
  }

  ll ans = 0;
  for (auto p : t){
    ans = max(ans, p.second);
  }
  cout << ans << endl;



  return 0;
}
