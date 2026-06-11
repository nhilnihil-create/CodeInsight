#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (ll i=0; i<(n); ++i)
typedef long long ll;
bool debug=false;
string yes = "Yes";
string no = "No";
ll mod = 1000000007;

int main(){
  ll n,k; cin >> n >> k;
  vector<ll> v(n+1,0);
  rep(i,n){
    cin >> v[i+1];
  }
  vector<vector<ll>> from_l(n+1, vector<ll>(n+1,0));
  priority_queue<ll,vector<ll>,greater<ll>> pq_l;
  for(ll i=1; i<=n; i++){
    if(v[i]<0){pq_l.push(v[i]);}
    from_l[i][0]+=from_l[i-1][0]+v[i];
    priority_queue<ll,vector<ll>,greater<ll>> cp(pq_l);
    ll cnt=0;
    while(cp.size()>0){
      cnt++;
      ll t = cp.top(); cp.pop();
      from_l[i][cnt]=from_l[i][cnt-1]-t;
    }
    from_l[i].resize(cnt+1);
  }
  if(debug){
    cout << "from_l" << endl;
    for(auto e: from_l){
      for(auto f: e){
        cout << f << " ";
      }
      cout << endl;
    }    
  }
  vector<vector<ll>> from_r(n+1, vector<ll>(n+1,0));
  priority_queue<ll,vector<ll>,greater<ll>> pq_r;
  for(ll i=1; i<=n; i++){
    if(v[n-i+1]<0){pq_r.push(v[n-i+1]);}
    from_r[i][0]+=from_r[i-1][0]+v[n-i+1];
    priority_queue<ll,vector<ll>,greater<ll>> cp(pq_r);
    ll cnt=0;
    while(cp.size()>0){
      cnt++;
      ll t = cp.top(); cp.pop();
      from_r[i][cnt]=from_r[i][cnt-1]-t;
    }
    from_r[i].resize(cnt+1);
  }
  if(debug){
    cout << "from_r" << endl;
    for(auto e: from_r){
      for(auto f: e){
        cout << f << " ";
      }
      cout << endl;
    }
  }
  ll ans=0;
  rep(i_l,n+1)rep(j_l,n+1)rep(i_r,n+1)rep(j_r,n+1){
    if(i_l+i_r+j_l+j_r>k) continue;
    if(i_l+i_r>n) continue;
    if(from_l[i_l].size()-1>=j_l){
      if(from_r[i_r].size()-1>=j_r){
        ans=max(ans, from_l[i_l][j_l]+from_r[i_r][j_r]);
      }
    }
  }
  cout << ans;
  return 0;
}