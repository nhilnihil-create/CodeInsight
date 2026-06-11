#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define len(v) ll(v.size())
#define fi first
#define se second

template <class T>
void cout_vec(const vector<T> &vec){
  for(auto itr:vec) cout<<itr<<' ';
  cout<<endl;
}

typedef pair<ll,ll> P;
const ll mod=1e9+7;
const ll inf=1e15;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n,k;
  cin>>n>>k;
  vector<P> a(n);
  vector<int> used(n+1,0);
  priority_queue<P,vector<P>,greater<P>> cnt;
  rep(i,n) cin>>a[i].se>>a[i].fi;
  sort(begin(a),end(a),greater<P>());
  ll ans=0,kind=0;
  rep(i,k){
    ans+=a[i].fi;
    if(used[a[i].se]) cnt.push(P(a[i].fi,a[i].se));
    else kind++;
    used[a[i].se]++;
  }
  ans+=kind*kind;
  //cout<<ans<<endl;
  ll former=ans;
  FOR(i,k,n){
    if(used[a[i].se]) continue;
    if(!cnt.empty()){
      used[a[i].se]++;
      ll x=former;
      P now=cnt.top();
      cnt.pop();
      if(used[now.se]==1) continue;
      used[now.se]--;
      x-=now.fi;
      x+=a[i].fi;
      x-=kind*kind;
      x+=(kind+1)*(kind+1);
      kind++;
      //cout<<a[i].se<<' '<<a[i].fi<<' '<<x<<endl;
      ans=max(ans,x);
      former=x;
    }
    //cout<<ans<<endl;
  }
  //cout<<kind<<endl;
  cout<<ans<<endl;
}