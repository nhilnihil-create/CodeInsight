#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(ll i = 0; i<(ll)(n); i++)
#define REPS(i,n) for (ll i = 1; i<=(ll)(n); i++)
#define REPD(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define pb push_back
#define MOD 1000000007
#define MOD2 998244353
#define PI 3.141592653
#define INF 100000000000000

int main(){
    ll n; cin >> n;
    ll ans = 1000000000000000000;
    vector<ll> a(n);
    vector<ll> asum(n);
    vector<ll> ansl;
    REP(i,n){
        cin >> a[i];
        if (i) asum[i]=asum[i-1]+a[i];
        else asum[i]=a[i];
    }
    FOR(i,1,n-3){
        ll ind1 = lower_bound(asum.begin(),asum.end(),asum[i]/2)-asum.begin();
        ll ind2 = lower_bound(asum.begin(),asum.end(),(asum[n-1]-asum[i])/2+asum[i])-asum.begin();
        //cout << i << " " << ind1 << " " << ind2 << endl;
        FOR(j,ind1-1,ind1+1)FOR(k,ind2-1,ind2+1){
            if (j!=-1&&k!=n){
                ll minc = min(asum[j],asum[i]-asum[j]);
                minc = min(minc,asum[k]-asum[i]);
                minc = min(minc,asum[n-1]-asum[k]);
                ll maxc = max(asum[j],asum[i]-asum[j]);
                maxc = max(maxc,asum[k]-asum[i]);
                maxc = max(maxc,asum[n-1]-asum[k]);
                ans = min(ans,maxc-minc);
                //cout << j << " " << i << " " << k << " " << maxc << " " << minc << endl;
            }
        }
    }
    cout << ans << endl;
}