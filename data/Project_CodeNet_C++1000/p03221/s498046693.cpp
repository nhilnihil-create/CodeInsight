#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1000000000000000000

using namespace std;

string lltozeroume(ll a){
  if (a >= 100000){
    return to_string(a);
  }
  else if (a >= 10000){
    return "0" + to_string(a);
  }
  else if (a >= 1000){
    return "00" + to_string(a);
  }
  else if (a >= 100){
    return "000" + to_string(a);
  }
  else if (a >= 10){
    return "0000" + to_string(a);
  }
  else if (a >= 1){
    return "00000" + to_string(a);
  }
}

int main(void){
  ll n, m;
  cin >> n >> m;
  
  vector<string> ans(m);
  vector<tuple<ll,ll,ll>> input(m);
  for (int i = 0; i < m; i++){
    ll p, y;
    cin >> p >> y;
    
    input[i] = make_tuple(p, y, i);
  }
  sort(input.begin(), input.end());
  
  vector<ll> th(n + 1, 0);
  for (auto i : input){
    int index = get<2>(i);
    ll pref = get<0>(i);
    th[pref]++;
    ans[index] = lltozeroume(pref) + lltozeroume(th[pref]);
  }

  for (int i = 0; i < m; i++){
    cout << ans[i] << endl;
  }

  return 0;
}
