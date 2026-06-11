#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<long long> > vvll;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 5000000000000000LL
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define p_q priority_queue

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 200005
ll n;
ll x[MN];
ll ps[MN];
ll c; //x in problem!

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n >> c;
    FOR(i, 1, n){
        cin >> x[n+1-i];
        //ps[i] = ps[i-1]+x[i];
    }
    FOR(i, 1, n){
        ps[i] = ps[i-1]+x[i];
        //cout << ps[i] << " ";
    }
    //cout << "\n";

    ll ans = INF;

    FOR(i, 1, n){
        ll cm = 5;

        ll ca = 0;
        for(ll j=i; j<=n+i; j+=i){
            ll sm = ps[min(j, n)]-ps[j-i];

            ca += sm*cm;
            //cm+=2;
            if(j != i) cm += 2;
            if(ca > INF) ca = INF;
        }

        ca += c*(ll)(i+n);
        if(ca > INF) ca = INF;

        //cout << i << " " << ca << "\n";

        ans = min(ans, ca);
    }

    cout << ans << "\n";

    return 0;
}
