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
  ll n;cin>>n;
  vector<pair<ll,pair<ll,ll>>> A(n);
  for(int i=0;i<n;i++){
    ll a,b;cin>>a>>b;
    A[i] = mp(a+b,mp(a,b));
  }
  ll ans = 0;
  sort(ALL(A),greater<pair<ll,pair<ll,ll>>>());
  for(int i=0;i<n;i++)
    if(i%2){
      ans -= A[i].S.S;
    }else{
      ans += A[i].S.F;
    }
  cout<<ans<<endl;
  return 0;
}
