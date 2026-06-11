#include <bits/stdc++.h>
//#include <atcoder/all>
#define ll long long int
#define MOD 1000000007
#define P pair<ll,ll>
#define INF 1000000000000000000

//using namespace atcoder;
using namespace std;

int main(void){
  
  string s;
  cin >> s;
  
  ll k;
  cin >> k;

  vector<string> ss;
  for (ll i = 0; i < k; i++){
    for (ll j = 0; j < s.size()-i; j++){
      ss.emplace_back(s.substr(j, i+1));
    }
  }
  sort(ss.begin(), ss.end());
  ss.erase(unique(ss.begin(), ss.end()), ss.end());
  cout << ss[k-1] << endl;


  return 0;
}
