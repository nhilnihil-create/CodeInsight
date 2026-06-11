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

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n,m;cin>>n>>m;
  priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<>>que;
  for(int i=0;i<n;i++){
    ll a,b;cin>>a>>b;
    que.push(mp(a,b));
  }
  ll ans = 0;
  while(!que.empty()){
    ll va = que.top().F;
    ll num = que.top().S;
    que.pop();
    if(num >= m){
      ans += m * va;
      break;
    }else{
      m-=num;
      ans += num*va;
    }
  }
  cout<<ans<<endl;
  return 0;
}

