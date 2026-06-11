#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=mod*mod*3LL;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

template <class Abel> struct BIT {
    const Abel UNITY_SUM = 0LL;                       // to be set
    vector<Abel> dat;
   
    // [1, n]
    BIT(int n) : dat(n + 1, UNITY_SUM) { }
    void init(int n) { dat.assign(n + 1, UNITY_SUM); }
    
    // a is 1-indexed
    inline void add(ll a, Abel x) {
        for (ll i = a; i < (ll)dat.size(); i += i & -i)
            dat[i] = dat[i] + x;
    }
    
    // [1, a], a is 1-indexed
    inline Abel sum(ll a) {
        Abel res = UNITY_SUM;
        for (ll i = a; i > 0; i -= i & -i)
            res = res + dat[i];
        return res;
    }
    
    // [a, b), a and b are 1-indexed
    inline Abel sum(ll a, ll b) {
        return sum(b - 1) - sum(a - 1);
    }
};

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n, ri = 0LL, le = INF, mid, N = 100005LL;
    cin >> n;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin >> a[i], ri = max(ri, a[i]), le = min(le, a[i]);
    ri++;
    while(ri - le > 1LL){ 
    	mid = (ri + le) / 2LL;
    	vector<ll> b(n+1, 0LL);
    	for(ll i=0LL;i<n;i++){
    		if(a[i] >= mid) b[i+1] = 1LL;
    		else b[i+1] = -1LL;
        }
        for(ll i=0;i<n;i++) b[i+1] += b[i];
        BIT<ll> bit(n + N * 2LL);
        ll ans = 0LL;
        for(ll i=0;i<=n;i++){
        	ans += bit.sum(b[i] + N);
        	bit.add(b[i] + N, 1LL);
        }
        if(n*(n+1LL) <= ans * 4LL) le = mid;
        else ri = mid;
    }
    cout << le << endl;
    return 0;
}
