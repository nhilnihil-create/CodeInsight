#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<typename T> bool chmax(T &a,T b) {if(a<b) {a=b; return true;} return false;}
template<typename T> bool chmin(T &a,T b) {if(a>b) {a=b; return true;} return false;}
#define itn int
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(int)(n);i>=1;i--)
#define all(vec) vec.begin(),vec.end()
#define sortt(vec) sort((vec).begin(),(vec).end())
#define rsort(vec) sort((vec).rbegin(), (vec).rend())
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef tuple<ll,ll,ll> tlll;
typedef tuple<int,int,int> tiii;
const ll mod=1e9+7;
const int inf=2e9;
const ll lnf=9e18;

ll dp[100010];

int main(){
  itn n,k; cin >> n >> k;
  vector<pll> a(n);
  rep(i,n) cin >> a[i].se >> a[i].fi;
  rsort(a);
  ll ans=0;
  set<int> kind;
  vector<ll> pulllist;
  rep(i,k){
    if(kind.count(a[i].se)) pulllist.push_back(a[i].fi);
    ans+=a[i].fi;
    kind.insert(a[i].se);
  }
  ans+=kind.size()*kind.size();
  if(pulllist.size()==0){
    cout << ans << endl;
    return 0;
  }
  sortt(pulllist);
  vector<ll> spull(pulllist.size());
  spull[0]=pulllist[0];
  rep(i,pulllist.size()-1) spull[i+1]=spull[i]+pulllist[i+1];
  int ks0=kind.size();
  vector<ll> pushlist;
  for(int i=k;i<n;i++){
    if(!(kind.count(a[i].se))) pushlist.push_back(a[i].fi);
    kind.insert(a[i].se);
  }
  if(pushlist.size()==0){
    cout << ans << endl;
    return 0;
  }
  vector<ll> spush(pushlist.size());
  spush[0]=pushlist[0];
  rep(i,pushlist.size()-1) spush[i+1]=spush[i]+pushlist[i+1];
  ll ans0=ans;
  ans=ans0;
  rep(i,min(spull.size(),spush.size())){
    chmax(ans,ans0-ks0*ks0-spull[i]+spush[i]+(ks0+i+1)*(ks0+i+1));
  }
  cout << ans << endl;
}