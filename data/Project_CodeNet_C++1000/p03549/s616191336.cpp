#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
const int MOD=1e9+7;


ll binary_power(ll a, ll n) {
    if (n==0) return 1;
    ll k=binary_power(a,n/2);
    if (n%2==0) return (k*k)%MOD;
    else return (((k*k)%MOD)*a)%MOD;
}


int main() {
    ios_base::sync_with_stdio(false);

    int n,m;
    cin >> n >> m;
    double ans=0;
    double p=1;
    ll b=binary_power(2,m);
    double a=1.0/b;
    rep(i,1000000) {
        double tp=p*a;
        ans+=((n-m)*100+m*1900)*(i+1)*tp;
        p-=tp;
    }
    cout << ans << endl;
    return 0;
}