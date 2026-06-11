#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,ll>
const ll MOD=1e9+7;
const int INF=1e9;
const double PI=acos(-1);


int main() {
    ios_base::sync_with_stdio(false);

    ll n;
    cin >> n;
    ll m=n;
    ll d=0;
    while (m>0) {
        d+=m%10;
        m/=10;
    }
    if (n%d==0) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0; 
}
