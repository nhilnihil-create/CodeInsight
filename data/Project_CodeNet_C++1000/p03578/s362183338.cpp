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
using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n,m;cin>>n;
  map<ll,ll>cnt;
  while(n--){
    ll a;cin>>a;
    cnt[a]++;
  }
  bool fl = true;
  cin>>m;
  while(m--){
    ll a;cin>>a;
    if(cnt[a] == 0)fl =false;
    else cnt[a]--;
  }
  if(fl)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}
