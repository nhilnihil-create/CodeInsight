#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
#define all(a) (a).begin(),(a).end()
#define mk make_pair
ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=10000000000000000;


int main(){
  int q;
  cin >> q;
  rep(i,q){
    ll a,b;
    cin >> a >> b;
    ll f=min(a,b);
    ll g=max(a,b);
    ll ans=f-1;
    ll l=f+1,r=g+10;
    while(l!=r){
      ll mid=(l+r)/2;
      ll c=(f*g-1)/(mid);
      if (c<=mid) r=mid;
      else l=mid+1;
    }
    ans+=l-1-f;
    ans+=(f*g-1)/l;
    cout << ans << endl;
  }
}
