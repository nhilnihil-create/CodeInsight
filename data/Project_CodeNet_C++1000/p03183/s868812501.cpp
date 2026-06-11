#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
 
#define pii pair<ll, ll>
#define F first
#define S second
#define pb push_back
#define mp make_pair
 
const int N = 1e5 + 5;
const int mod = 1e9+7;
const ll INF = (ll)1e18;

inline int mul(int a, int b){
    return ((ll)a * b) % mod;
}

inline int add(int a, int b){
    int ans = a + b;
    if(ans >= mod) ans -= mod;
    return ans; 
}

// credits : codeforces :https://codeforces.com/blog/entry/54396
bool isprime(ll n){
    if(n<2) return false;
    for(ll i=2;i*i*i<=n;++i) if(n%i==0) return false;
    for(int it=0;it<1e2;++it){
        ll i = rand()%(n-1)+1;
        if(__gcd(i,n)!=1) return false;
        // if(mpow(i,n-1,n)!=1) return false;
    }
    return true;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector< pair<pii, ll> > v(n);
    for(int j = 0; j < n; j++) cin >> v[j].F.F >> v[j].F.S >> v[j].S;
    sort(v.begin(), v.end(), [](const pair<pii, int>& p1, const pair<pii, int>& p2){
        int f1 = p1.F.F <= p2.F.S;
        int f2 = p2.F.F <= p1.F.S;
        if(f1 && f2){
            // equal
            return (int)(p1.F.S-p2.F.F < p2.F.S-p1.F.F);
        } 
        if(f1) return 1;
        if(f2) return 0;
        // no matter what to put first. So, equal
        // return 0;
        return (int)(p1.F.S*p2.F.F > p2.F.S*p1.F.F); 
    });
    // for(auto i : v) cout << "(" << i.F.F << " " << i.F.S << " " << i.S << ") "; cout << endl;

    vector<ll> dp(20005, 0);
    for(int j = 0; j < n; j++){
        ll w = v[j].F.F, s = v[j].F.S, val = v[j].S;
        for(int j = s; j >= 0; j--)
            dp[j+w] = max(dp[j+w], val+dp[j]);
    }
    ll ans = 0;
    for(auto i : dp) ans = max(ans, i);
    cout << ans << '\n';
    return 0;
}
