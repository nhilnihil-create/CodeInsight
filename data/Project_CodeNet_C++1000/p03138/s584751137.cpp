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
const int INF=2e9;
const double PI=acos(-1);



int main() {
    ios_base::sync_with_stdio(false); 

    ll n,k;
    cin >> n >> k;
    bitset<42> kk(k);
    vector<int> bit(42);
    vector<ll> pow_two(42),a(n);
    pow_two[0]=1;
    rep(i,41) pow_two[i+1]=pow_two[i]*2;
    rep(i,n) {
        cin >> a[i];
        bitset<42> aa(a[i]);
        rep(j,42) {
            if (aa[j]==1) ++bit[j];
        }
    }
    bool flag=0;
    ll x=0;
    invrep(i,42) {
        if (!flag) {
            if (kk[i]>0) {
                if (bit[i]>=(n+1)/2) flag=1;
                else x+=pow_two[i];
            }
        } else {
            if (bit[i]<(n+1)/2) x+=pow_two[i]; 
        }
    }
    ll ans=0;
    rep(i,n) ans+=x^a[i];
    cout << ans << endl;
     
    return 0;
}
