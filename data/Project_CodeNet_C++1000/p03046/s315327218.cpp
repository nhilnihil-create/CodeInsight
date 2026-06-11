#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,int>
const int MOD=1e9+7;
const int INF=1e9;
const double PI=acos(-1);


ll binary_power(ll a, ll n) {
    if (n==0) return 1;
    ll k=binary_power(a,n/2);
    if (n%2==0) return (k*k)%MOD;
    else return (((k*k)%MOD)*a)%MOD;
}


int main() {
    ios_base::sync_with_stdio(false); 

    ll m,k;
    cin >> m >> k;
    ll p=pow(2,m);
    if (k==0) {
        rep(i,p) cout << i << ' ' << i << ' ';
        cout << endl;
    } else if (m==1 && k==1) {
        cout << -1 << endl;
    } else if (k<=p-1) {
        rep(i,k) cout << i << ' ';
        cout << k << ' ';
        invrep(i,k) cout << i << ' ';
        repr(i,k+1,p) cout << i << ' ';
        cout << k << ' ';
        invrepr(i,k+1,p) cout << i << ' ';
        cout << endl;
    } else cout << -1 << endl;

    return 0;
}
