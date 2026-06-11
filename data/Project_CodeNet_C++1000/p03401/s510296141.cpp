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

    int n;
    cin >> n;
    vector<int> a(n+2);
    rep(i,n) cin >> a[i+1];
    ll d=0;
    rep(i,n+1) d+=abs(a[i]-a[i+1]);
    repr(i,1,n+1) {
        int ans=d-(abs(a[i+1]-a[i])+abs(a[i]-a[i-1])-abs(a[i+1]-a[i-1]));
        cout << ans << endl;
    }
    return 0;
}