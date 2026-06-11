#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
const ll INF = (ll)1e18 *4 +9;

int f(vector<int> v, int k){//ソート済みの配列からk個取る時の差の最小値を返す
  int n = v.size();
  int ans = v[k-1] - v[0];
  for(int i=k; i<n; ++i){
    ans = min(ans, v[i] - v[i-k+1]);
  }
  return ans;
}

int main(){
  int n, k;
  cin >> n >> k;
  vector<P> v(n);
  for(int i=0; i<n; ++i) cin >> v[i].first >> v[i].second;
  sort(v.begin(),v.end());
  ll ans = INF;
  for(int i=0; i<n-k+1; ++i){
    vector<int> v2;
    for(int i2=i; i2<i+k-1; ++i2) v2.push_back(v[i2].second);
    for(int j=i+k-1; j<n; ++j){
      int disx = v[j].first - v[i].first;
      v2.push_back(v[j].second);
      sort(v2.begin(),v2.end());
      int disy = f(v2,k);
      ans = min(ans, (ll)disx * disy);
    }
  }
  cout << ans << endl;
}