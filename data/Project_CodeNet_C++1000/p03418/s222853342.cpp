#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n,k;
  cin >> n >> k;
  ll ans=0;
  for(ll i=k+1; i<=n; i++){
    ll l=i-k;
    ans += n;
    ans -= max(k-1, 0LL)*(n/(k+l));
    if(k!=0) ans-=n/(k+l);
    ans -= (n%(k+l) -max(n%(k+l) -max(k-1, 0LL),0LL));
    //    cout << n%(k+l) << "-" << max(k-1-1+1, 0) << endl;
    /*    ans+=l*n/(k+l);
    ans+=max(n%(k+l)-(k-1),0);
    if(k==0) ans-=1;*/
    //        cout << ans << endl;
  }
  cout << ans << endl;
  
  return 0;
    

}
