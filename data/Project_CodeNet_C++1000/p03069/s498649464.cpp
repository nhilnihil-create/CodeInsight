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
vi w(222222),b(222222);
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;cin>>n;
  string s;cin>>s;
  for(int i=0;i<n;i++){
    if(s[i] == '#'){
      b[i+1] = b[i]+1;
      w[i+1] = w[i];
    }else{
      b[i+1] = b[i];
      w[i+1] = w[i]+1;
    }
  }
  ll ans = llINF;
  for(int i=0;i<=n;i++){
    ans = min(ans,b[i]+w[n]-w[i]);
  }
  cout<<ans<<endl;
  return 0;
}
