#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll> PLL;
typedef pair<P,P> PP;
typedef vector<ll> VECLL;
typedef vector<P> VECP;
typedef priority_queue<P,VECP,greater<P> > PQP;
typedef priority_queue<ll, VECLL, greater<ll> > PQll;

#define rep(i,a,n) for(ll i = a;i < n;i++)   
#define rrep(i,a,n) for(ll i = n; i >= a;i--)
#define index_check(i,n) if(i > n-1 || i < 0) continue; 
#define LINF (ll)1e18
#define INF (int)1e9
#define fs first
#define sc second

#include <bits/stdc++.h>
#define rep(i,a,n) for(ll i = a;i < n;i++)
typedef long long ll;
using namespace std;

#define SEG_LEN (1 << 18)

ll seg[SEG_LEN*2];

ll gcd(ll a,ll b){
    if(!b) return a;
    return gcd(b,a%b);
}


void set_num(ll ind, ll v){
    ind += SEG_LEN;
    seg[ind] += v;
    while(1){
        ind /= 2;
        if(ind == 0) break;

        seg[ind] = gcd(seg[ind*2], seg[ind*2+1]);
    }
}

ll get_gcd(ll l, ll r){
    l += SEG_LEN;
    r += SEG_LEN;
    ll res = 0;
    while(l < r){
        if(l % 2 == 1){
            res = gcd(res,seg[l]);
            l++;
        }
        l /= 2;

        if(r % 2 == 1){
            res = gcd(res,seg[r-1]);
            r--;
        }
        r /= 2;
    }

    return res;
}


int main(){ 
    
    ll n;
    cin >> n;
    
    rep(i,0,n){
        ll a;
        cin >> a;
        set_num(i+1,a);
    }

    ll ans = 1;
    rep(i,0,n){
        if(i == 0) ans = max(ans,get_gcd(i+2,n+1));
        else if(i == n-1) ans =  max(ans, get_gcd(1,i+1) );
        else ans = max(ans,gcd(get_gcd(1,i+1),get_gcd(i+2,n+1)) );

    }

    cout << ans << endl;
    return 0;
}
