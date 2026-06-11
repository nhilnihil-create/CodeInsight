#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  ll n, K;
  cin >> n >> K;
  vector < pair < ll, ll > > pts;
  for(int i = 0; i < n; i++){
    ll x, y;
    cin >> x >> y;
    pts.push_back({x, y});
  }

  sort(pts.begin(), pts.end());

  ll area = LLONG_MAX;
  for(int i = 0; i < n; i++){
    for(int j = i + 1; j < n; j++){
      if(j - i + 1 < K) continue;
      vector < ll > v;
      for(int k = i; k <= j; k++) v.push_back(pts[k].second);
      sort(v.begin(), v.end());
      ll mi = LLONG_MAX;
      for(int k = 0; k < v.size() && K + k - 1 < v.size(); k++){
        mi = min(mi, v[K - 1 + k] - v[k]);
      }
      ll tmp_area = mi;
      tmp_area *= (pts[j].first - pts[i].first);
      area = min(area, tmp_area);
    }
  }

  cout << area << '\n';
}
