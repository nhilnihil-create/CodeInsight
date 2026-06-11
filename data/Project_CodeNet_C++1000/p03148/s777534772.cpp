#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
template<class T> using V=vector<T>; 
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
//const ll mod=998244353;
const ll mod=1000000007;
ll GCD(ll a,ll b) {return b ? GCD(b,a%b):a;}
ll LCM(ll c,ll d){return c/GCD(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
int main(){
  ll n,k;
  cin>>n>>k;
  ll ans=0;
  V<P> d(n);
  V<int> cnt(n,0);
  priority_queue<P> pq;
  priority_queue<P,V<P>,greater<P>> q;
  for(int i=0;i<n;i++){
	  cin>>d[i].se>>d[i].fi;
	  d[i].se--;
	  pq.push(d[i]);
  }
  ll res=0;
  ll sum=0;
  while(pq.size()){
	  res+=pq.top().fi;
	  cnt[pq.top().se]++;
	  q.push(pq.top());
	  pq.pop();
	  sum++;
	  if(sum==k)break;
  }
  ll t=0;
  for(int i=0;i<n;i++)if(cnt[i])t++;
  ans=res+t*t;
  sum=0;
  while(pq.size()){
	  if(cnt[pq.top().se]){
		  pq.pop();
		  continue;
	  }
	  while(q.size()){
		  if(cnt[q.top().se]==1){
			  sum+=q.top().fi;
			  res-=q.top().fi;
			  q.pop();
		  }else{
			  res-=q.top().fi;
			  cnt[q.top().se]--;
			  q.pop();
			  sum+=pq.top().fi;
			  cnt[pq.top().se]=1;
			  t++;
			  break;
		  }
	  }
	  chmax(ans,res+sum+t*t);
	  pq.pop();
  }
  cout<<ans<<"\n";
}