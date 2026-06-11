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
  string a,b,c;cin>>a>>b>>c;
  ll ans = 0;
  for(int i=0;i<n;i++){
    set<char>se;
    se.insert(a[i]);
    se.insert(b[i]);
    se.insert(c[i]);
    ans += se.size()-1;
  }
  cout<<ans<<endl;
  return 0;
}