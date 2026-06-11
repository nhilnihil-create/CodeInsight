#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  int n, k;
  cin >> n >> k;
  vector < pair < int, int > > v;
  for(int i = 0; i < n; i++){
    int t, d;
    cin >> t >> d;
    v.push_back({d, t});
  }

  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  priority_queue < int, vector < int >, greater < int > > q;
  vector < bool > used(n + 1, false);
  ll y = 0, x = 0;
  for(int i = 0; i < k; i++){
    y += v[i].first;
    if(!used[v[i].second]){
      used[v[i].second] = true;
      x++;
    }else{
      q.push(v[i].first);
    }
  }

  ll ans = y + x * x;
  for(int i = k; i < n && !q.empty(); i++){
    if(used[v[i].second]) continue;
    x++;
    y -= q.top();
    q.pop();
    y += v[i].first;
    used[v[i].second] = true;
    ans = max(ans, x * x + y);
  }

  cout << ans << '\n';
}
