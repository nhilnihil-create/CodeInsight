#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 998244353LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 1000005
int l;
int n;
vector<pair<pii, int> > e;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> l;
    if(l == 1){
        cout << "2 1\n1 2 0\n";
        return 0;
    }
    n = 1;
    while(1<<(n+1) <= l) n++;
    FOR(i, 1, n){
        e.pb({{i, i+1}, 0});
        e.pb({{i, i+1}, 1<<(i-1)});
    }
    int cur = (1<<n);
    RFOR(i, n-1, 0){
        if((1<<i) & l){
            e.pb({{i+1, n+1}, cur});
            cur += (1<<i);
        }
    }
    cout << n+1 << " " << e.size() << "\n";
    for(auto u : e) cout << u.f.f << " " << u.f.s << " " << u.s << "\n";
    
    return 0;
}
