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


ll gcd(ll a,ll b) {
    if (a<b) swap(a,b);
    while (b>0) {
        ll tmp=b;
        b=a%b;
        a=tmp;
    }
    return a;
}


int main() {
    ios_base::sync_with_stdio(false); 

    int t;
    cin >> t;
    rep(i,t) {
        ll a,b,c,d;
        cin >> a >> b >> c >> d;
        bool flag=1;
        if (a<b || d<b) flag=0;
        else if (c<b) {
            a=a%b;
            ll s=d%b;
            ll g=gcd(b,s);
            if (b-g+(a%g)>c) flag=0;
        }
        if (flag) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}
