#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,int>
const ll MOD=1e9+7;
const int INF=2e9;
const double PI=acos(-1);

const int MAX=200010;


int main() {
    ios_base::sync_with_stdio(false); 

    vector<int> c(3);
    int k;
    rep(i,3) cin >> c[i];
    cin >> k;
    vector<vector<ll>> a(3);
    rep(i,3) {
        rep(j,c[i]) {
            ll x;
            cin >> x;
            a[i].push_back(x);
        }
        sort(a[i].begin(),a[i].end(),greater<>());
    }
    vector<ll> s(c[0]*c[1]);
    rep(i,c[0]) {
        rep(j,c[1]) s[i*c[1]+j]=a[0][i]+a[1][j];
    }
    sort(s.begin(),s.end(),greater<>());
    int m=min(k,c[0]*c[1]);
    vector<ll> t(c[2]*m);
    rep(i,m) {
        rep(j,c[2]) t[i*c[2]+j]=s[i]+a[2][j];
    }
    sort(t.begin(),t.end(),greater<>());

    rep(i,k) cout << t[i] << endl;
    
    return 0;
}
