#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
  // input
  ll n, m;
  cin >> n >> m;

  // distribute each prefecture
  vector<vector<ll>> r(100010);
  vector<ll> p(m), y(m);
  rep(i, 0, m){
    cin >> p[i] >> y[i];
    r[p[i]].push_back(y[i]);
  }
  
  // in prefecture, x set
  map<ll, bool> seen;
  vector<map<ll, ll>> o(100010); // o[prefecture][year] 
  for(auto t : p){
    if(seen[t]) continue;
    seen[t] = true;
    sort(r[t].begin(), r[t].end());
    rep(i, 0, r[t].size()){
        o[t][r[t][i]] = i + 1;  
    }
  }

  rep(i, 0, m){
    string s = to_string(p[i]);
    // front id
    ll lm = s.size();
    rep(j, 0, 6-lm){
        s = "0" + s;
    }
    // back id
    ll ty = o[p[i]][y[i]];
    string ss = to_string(ty);
    lm = ss.size();
    rep(j, 0, 6-lm){
        ss = "0" + ss;
    }
    cout << s + ss << endl;
  }

  return 0;
}
