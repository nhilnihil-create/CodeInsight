#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (ll i=0; i<(n); ++i)
typedef long long ll;
bool debug=false;
string yes = "Yes";
string no = "No";

int main(){
  ll n; cin >> n;
  ll cnt74=0;
  ll cnt24=0;
  ll cnt14=0;
  ll cnt4=0;
  ll cnt2=0;
  vector<ll> v{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
  for(auto d:v){
    ll cnt=0;
    for(ll i=n;i>0;i--){
      ll t=i;
      while(t%d==0){
        t/=d;
        cnt++;
      }
    }
    if(cnt>=74) cnt74++;
    if(cnt>=24) cnt24++;
    if(cnt>=14) cnt14++;
    if(cnt>=4) cnt4++;
    if(cnt>=2) cnt2++;
  }
  ll ans = cnt74;
  ans += (cnt2-cnt24)*cnt24+cnt24*(cnt24-1);
  ans += (cnt4-cnt14)*cnt14+cnt14*(cnt14-1);
  ans += ((cnt2-cnt4)*cnt4*(cnt4-1)/2)+(cnt4*(cnt4-1)*(cnt4-2)/2);
  cout << ans << endl;
  return 0;
}
