#include <bits/stdc++.h>
#define ft first
#define sc second
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define pt(sth) cout << sth << "\n"
#define chmax(a, b) {if(a<b) a=b;}
#define chmin(a, b) {if(a>b) a=b;}
#define moC(a, s, b) (a)=((a)s(b)+MOD)%MOD
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
static const ll INF=1e18;
static const ll MAX=1e5+7;
static const ll MOD=1e9+7;


int main() {
    ll N, K;
    cin >> N >> K;
    ll a[MAX], b[MAX];
    ll i, j;
    
    for(i=0; i<N; i++)
        cin >> a[i] >> b[i];
    
    ll ans=0;
    
    for(i=0; i<N; i++) {
        if((K|a[i])==K)
            ans+=b[i];
    }
    
    for(i=30; i>=0; i--) {
        if(!(1&K>>i)) continue;
        
        ll mask=K-(1<<i)|((1<<i)-1);
        ll s=0;
        for(j=0; j<N; j++) {
            if((mask|a[j])==mask)
                s+=b[j];
        }
        
        chmax(ans, s);
    }
    
    pt(ans);
    
}
