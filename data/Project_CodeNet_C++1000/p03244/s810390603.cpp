#include<bits/stdc++.h>
#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define BITLE(n) (1LL<<((ll)n))
#define SHIFT_LEFT(n) (1LL<<((ll)n))
#define SUBS(s,f,t) ((s).substr((f),(t)-(f)))
#define ALL(a) (a).begin(),(a).end()
#define Max(a) (*max_element(ALL(a)))
#define Min(a) (*min_element(ALL(a)))
using namespace std;
vector<pair<ll,ll>>pll,pll2;
ll cnt[3][111111];
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;cin>>n;

  for(int i=0;i<n;i++){
    ll a;cin>>a;
    cnt[i%2][a]++;
  }
  ll od = 0,ev = 0;
  for(int i=0;i<111111;i++){
    if(cnt[0][i])pll.pb(mp(cnt[0][i],i));
    if(cnt[1][i])pll2.pb(mp(cnt[1][i],i));
  }
  pll.pb(mp(0,0));
  pll2.pb(mp(0,0));
  sort(ALL(pll),greater<pair<ll,ll>>());
  sort(ALL(pll2),greater<pair<ll,ll>>());
  if(pll[0].S == pll2[0].S){
    cout<<n-max(pll[1].F+pll2[0].F,pll[0].F+pll2[1].F)<<endl;
  }else{
    cout<<n-pll[0].F-pll2[0].F<<endl;
  }
    return 0;
}

