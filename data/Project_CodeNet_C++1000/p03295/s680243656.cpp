#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  int n, m;
  cin >> n >> m;
  vector < pair < int, int > > v;
  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    v.push_back({b, a});
  }
  sort(v.begin(), v.end());
  int ans = 1, broke;
  broke = v[0].first - 1;
  for(int i = 1; i < m; i++){
    if(broke < v[i].first && broke >= v[i].second) continue;
    ans++;
    broke = v[i].first - 1;
  }

  cout << ans << '\n';
}
