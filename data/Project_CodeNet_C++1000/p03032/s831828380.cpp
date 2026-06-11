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
  ll n,k;cin>>n>>k;
  vi A(n);
  ll ans = 0;
  for(auto &a:A)cin>>a;
  for(int i=0;i<n;i++){
    for(int j=n;j>=i;j--){
      ll num = i + n-j;
      if(num > k)continue;
      vi ju;
      for(int ii=0;ii<i;ii++){
	ju.pb(A[ii]);
      }
      for(int ii=n-1;ii>=j;ii--){
	ju.pb(A[ii]);
      }
      sort(ALL(ju),greater<ll>());
      ll cnt = 0;
      while(cnt < k-num && ju.size()){
	if(ju.back() < 0)ju.pop_back();
	else break;
	cnt++;
      }
      ll sum = 0;
      for(auto a:ju){
	sum += a;
      }
      ans = max(sum,ans);
    }
  }
  cout<<ans<<endl;
  return 0;
}

