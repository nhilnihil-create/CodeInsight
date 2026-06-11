#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
const int MOD=1e9+7;



int main() {
    ios_base::sync_with_stdio(false); 

    ll n,m;
    cin >> n >> m;
    ll ans;
    if (n==1 && m==1) ans=1;
    else if (n==1) ans=m-2;
    else if (m==1) ans=n-2;
    else ans=(n-2)*(m-2);
    cout << ans << endl;
    return 0;
}