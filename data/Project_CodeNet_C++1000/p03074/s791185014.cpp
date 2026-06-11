#include <bits/stdc++.h>
//#include <atcoder/all>
#define ll long long int
#define MOD 1000000007
#define P pair<ll,ll>
#define INF 1000000000000000000

//using namespace atcoder;
using namespace std;

int main(void){
  ll n, k;
  cin >> n >> k;
  
  string s;
  cin >> s;
  
  vector<vector<ll>> data(2, vector<ll>(0));
  int cur = 1, num = 0;
  for (ll i = 0; i < s.size(); i++){
    if (s[i] - '0' == cur){
      num++;
    }
    else {
      data[cur].emplace_back(num);
      num = 1;
      cur = 1 - cur;
    }
  }
  if (cur == 1)
    data[cur].emplace_back(num);
  else {
    data[0].emplace_back(num);
    data[1].emplace_back(0);
  }
  
  ll ans = 0, sum = 0;
  if (data[1].size() <= k){
    ans = n;
  }
  else {
    sum += data[1][0];
    for (ll i = 0; i < k; i++){
      sum += data[1][i+1];
      sum += data[0][i];
    }


    ans = sum;
    for (ll i = k; i < data[0].size(); i++){
      sum -= data[1][i-k];
      sum -= data[0][i-k];
      sum += data[1][i+1];
      sum += data[0][i];
      ans = max(ans, sum);
    }
  }
  cout << ans << endl;

  return 0;
}
