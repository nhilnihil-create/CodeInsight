#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define DUMP(x)  cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define IFOR(i, m, n) for(ll i = n - 1; i >= m; i-- )
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define FOREACH(x,a) for(auto& (x) : (a) )
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) ll(x.size())

int main(){
  ll N; cin >> N;
  vector<ll> cnt(13,0), D(N+1);
  D[0] = 0; cnt[0]++; //高橋くん
  REP(i,N){
    cin >> D[i+1];
    cnt[D[i+1]]++;
  }
  //0,12が2人以上いれば,必ずs=0
  if(cnt[0]>=2 || cnt[12]>=2){
    cout << 0 << endl;
    return 0;
  }
  //D(>=1)が同じ人が3人以上いれば，必ずs=0
  FOR(i,1,13){
    if(cnt[i]>=3){
      cout << 0 << endl;
      return 0;
    }
  }
  //同じDを取る人は2人以下
  //2人いる場合は別時刻としてよい
  ll U = (1<<12);
  ll ans = 0;
  vector<bool> use(24,false);
  use[0] = true;
  FOR(i,1,13){
    if(cnt[i]==2){
      use[i] = true;
      use[24-i] = true;
    }
  }
  REP(i,U){
    vector<bool> use2 = use;
    FOR(j,1,13){
      if(cnt[j]!=1) continue;
      if(i&(1<<(j-1))) use2[j] = true;
      else use2[24-j] = true;
    }
    ll mini = 1e18;
    REP(i,23) FOR(j,i+1,24) if(use2[i]&&use2[j]){
      ll b = j-i;
      mini = min(mini, min(b,24-b));
    }
    ans = max(ans,mini);
  }
  cout << ans << endl;
}