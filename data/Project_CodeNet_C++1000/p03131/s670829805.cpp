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
  ll k,a,b;cin>>k>>a>>b;
  if(b > a){
    ll num = k-a+1;
    ll ans = a + num%2 + (b-a)*(num/2);
    cout<<max(ans,k+1)<<endl;
  }else{
    cout<<k+1<<endl;
  }
  return 0;
}
