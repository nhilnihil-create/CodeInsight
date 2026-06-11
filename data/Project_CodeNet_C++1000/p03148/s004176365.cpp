#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 1e9+1;
const ll INFll = (ll)1e18+1;
ll MOD=1e9+7;


int main(){
  int N,K;
  cin>>N>>K;
  vector<pair<ll,ll>> x;
  for(int i(0);i<N;i++){
    int t,d;
    cin>>t>>d;
    x.push_back({d,t});
  }
  sort(x.rbegin(),x.rend());
  ll sum(0);
  int used[100001] = {0};
  priority_queue<ll, vector<ll>, greater<ll> > q;
  priority_queue<ll> p;
  ll cnt(0);
  for(int i(0);i<K;i++){
    sum += x[i].first;
    used[x[i].second]++;
    if(used[x[i].second] >= 2) q.push(x[i].first);
    else cnt++;
  }

  for(int i(0);i<N;i++){
    if(used[x[i].second] == 0){
      p.push(x[i].first);
      used[x[i].second] = 1;
    }
  }
  ll ans = sum + cnt*cnt;
  while(!q.empty() && !p.empty()){
    // if(q.top() >= p.top() + cnt*cnt-(cnt-1)*(cnt-1)){
    //   break;
    // }
    sum -= q.top();q.pop();
    sum += p.top();p.pop();
    cnt++;
    ans = max(ans,sum+cnt*cnt);
  }
  cout << ans << endl;
  return 0;
}
