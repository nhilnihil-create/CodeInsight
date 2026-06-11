#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vvvll = vector<vector<vector<ll>>>;
using vvvvll = vector<vector<vector<vector<ll>>>>;
using pl4 = pair<ll,ll>;
using str = string;
using vpl4 = vector<pair<ll,ll>>;

#define sz size()
#define be begin()
#define en end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair

#define llin(x) ll(x);cin >> (x);
#define stin(x) str(x);cin >> (x);
#define vllin(x,n) vll(x)(n);FOR(i,0,n-1){cin >> (x)[i];}
#define vllin2(a,b,n) vll(a)(n);vll(b)(n);FOR(i,0,n-1){cin >> (a)[i] >> (b)[i];}
#define vllin3(a,b,c,n) vll(a)(n);vll(b)(n);vll(c)(n);FOR(i,0,n-1){cin >> (a)[i] >> (b)[i] >> (c)[i];}
#define vlling(x,n) (x).assign(n,0);FOR(i,0,n-1){cin >> (x)[i];}
#define vlling2(a,b,n) (a).assign(n,0);(b).assign(n,0);FOR(i,0,n-1){cin >> (a)[i] >> (b)[i];}
#define vlling3(a,b,c,n) (a).assign(n,0);(b).assign(n,0);(c).assign(n,0);FOR(i,0,n-1){cin >> (a)[i] >> (b)[i] >> (c)[i];}
#define vpl4in(x,n) vpl4(x)((n),mp(0,0));FOR(i,0,n-1){cin >> x[i].fi >> x[i].se;}
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define rFOR(i,b,a) for(ll i=a;i>=b;i--)
#define SORT(x) sort(x.be,x.en)
#define rSORT(x) sort(x.rbegin(),x.rend())
#define say(x) cout << (x);
#define sal(x) cout << (x) << endl;
#define says(x) cout << (x) << (' ');
#define sas cout << (' ');
#define sayR(x) cout << fixed << setprecision(10) << (x);
#define salR(x) cout << fixed << setprecision(10) << (x) << endl;
#define yn(a) cout << ((a) ? "yes" : "no") << endl;
#define Yn(a) cout << ((a) ? "Yes" : "No") << endl;
#define YN(a) cout << ((a) ? "YES" : "NO") << endl;
#define Imp(a) cout << ((a) ? "Possible" : "Impossible") << endl;
#define IMP(a) cout << ((a) ? "POSSIBLE" : "IMPOSSIBLE") << endl;

ll MOD = 1000000007;

vvll p(100001,vll(0,0));
vpl4 o(100001,mp(0,0));

pair<ll,ll> solve(ll t){
    if(o[t].fi>0) return o[t];
    pair<ll,ll> q=mp(0,0);
    ll d=0;
    ll r=0;
    for(auto l:p[t]){
        q=solve(l);
        if(q.se>=d){
            d=q.se+1;
            r=l;
        }
    }
    return o[t]=mp(r,d);
}

signed main()
{
    llin(n);
    llin(m);
    ll a,b=0;
    FOR(i,0,n-2+m){
        cin >>a>>b;
        p[b].pb(a);
    }
    FOR(i,1,n){
        sal(solve(i).fi)
    }
}