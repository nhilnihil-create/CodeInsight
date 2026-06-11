#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void tansaku(vector<vector<ll>>& path, vector<bool>& check, ll num);

int main(){
  ll N, M;
  cin >> N >> M;
  
  vector<vector<ll>> path(N + 1, vector<ll>(0));
  for (ll i = 0; i < M; i++){
    ll a, b, z;
    cin >> a >> b >> z;
    path.at(a).push_back(b);
    path.at(b).push_back(a);
  }
  
  vector<bool> check(N + 1, false);
  ll ans = 0;
  for (ll i = 1; i <= N; i++){
    if (check.at(i) == true){
      continue;
    }
    check.at(i) = true;
    tansaku(path, check, i);
    //cout << i << endl;
    ans++;
  }
  
  cout << ans << endl;
}

void tansaku(vector<vector<ll>>& path, vector<bool>& check, ll num){
  for (ll i : path.at(num)){
    if (check.at(i) == false){
      check.at(i) = true;
      tansaku(path, check, i);
    }
  }
  check.at(num) = true;
}