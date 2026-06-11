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
  int n,m;
  cin>>n>>m;
  vector<int> a(m);
  rep(i,m) cin>>a[i];
  sort(begin(a),end(a),greater<ll>());
  map<int,int> cnt;
  cnt[1]=2,cnt[2]=5,cnt[3]=5,cnt[4]=4;
  cnt[5]=5,cnt[6]=6,cnt[7]=3,cnt[8]=7,cnt[9]=6;
  vector<int> dp(n+1,-1e9);
  dp[0]=0;
  FOR(i,1,n+1){
    rep(j,m){
      if(i-cnt[a[j]]>=0) dp[i]=max(dp[i],dp[i-cnt[a[j]]]+1);
    }
  }
  string ans;
  int num=n;
  while(num){
    rep(i,m){
      if(num-cnt[a[i]]>=0 && dp[num-cnt[a[i]]]==dp[num]-1){
        ans.push_back((char)a[i]+'0');
        num-=cnt[a[i]];
        break;
      }
    }
  }
  cout<<ans<<endl;
}