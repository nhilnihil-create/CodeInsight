#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
signed main(){
  ll k,n,t_sum=0,ans,kind=0,v;
  cin >> n >> k;
  ll t[n],d[n];
  vector<P> sushi;
  vector<ll> vals[n];
  priority_queue<ll,vector<ll>,greater<ll>> que;
  map<ll,ll> mp;
  for(int i=0;i<n;i++){
    cin >> t[i] >> d[i];
    t[i]--;
    sushi.push_back(P(d[i],t[i]));
    vals[t[i]].push_back(d[i]);
  }
  sort(sushi.begin(),sushi.end(),greater<P>());
  if(k==1){
    cout <<sushi[0].first+1<<endl;
    return 0;
  }
  for(int i=0;i<k;i++){
    t_sum += sushi[i].first;
    mp[sushi[i].second]++;
  }
  kind = mp.size();
  ans = kind*kind+t_sum;
  for(int i=0;i<n;i++){
    if(vals[i].size()==0) continue;
    sort(vals[i].begin(),vals[i].end(),greater<ll>());
    if(mp.find(i)!=mp.end()){
      v = mp[i];
    }else{
      continue;
    }
    for(int j=1;j<v;j++){
      que.push(vals[i][j]);
    }
  }
  for(int i=k;i<n;i++){
    if(mp.find(sushi[i].second)==mp.end()){
      if(que.empty()){
        break;
      }
      t_sum -= que.top();
      que.pop();
      t_sum += sushi[i].first;
      mp[sushi[i].second]++;
      kind++;
      ans = max(ans,kind*kind+t_sum);
    }
  }
  cout << ans << endl;
}
