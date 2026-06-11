#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ll_s long
#define mod 1000000007
#define forn(i,start,lim) for(ll i=start;i<lim;i++)
#define forn_d(i,start,lim) for(ll i=start;i>=lim;i--)
#define f first
#define s second
#define pb push_back
#define pf push_front
#define mp make_pair
#define debug1(a) cout<<"------\n"<<#a<<" = "<<a<<endl<<"------"<<endl
#define debug2(a,b) cout<<"--------------\n"<<#a<<" = "<<a<<" ; "<<#b<<" = "<<b<<endl<<"--------------"<<endl
#define debug3(a,b,c) cout<<"----------------------\n"<<#a<<" = "<<a<<" ; "<<#b<<" = "<<b<<" ; "<<#c<<" = "<<c<<endl<<"----------------------"<<endl
#define sz(a) (ll)(a.size())
#define debug4(a) cout<<"chu "<<a<<endl
#define endl "\n"

int main()
{
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  ll t;
  // cin>>t;
  t=1;
  while(t--){
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n), dp(k+1,0);
    forn(i,0,n)
      cin>>a[i];
    forn(i,0,k+1){
      forn(j,0,n){
        if(i-a[j] >= 0 && dp[i-a[j]] == 0){
          dp[i] = 1;
          break;
        }
      }
    }
    ll ans = dp[k];
    if(ans == 1)
      cout<<"First\n";
    else
      cout<<"Second\n";
  }
  return 0;
}
