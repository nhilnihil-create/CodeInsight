#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

typedef int _loop_int;
#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

const ll MOD = 1000000007ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

ll n,m;
vl a;
ll ans = 0;
int main() {
    cin>>n>>m;

    a.resize(n);
    REP(i,n) cin>>a[i];

    vl csum(n+1);
    csum[0] = 0;
    FOR(i,0,n)
        csum[i+1] = (csum[i] + a[i]) % m;

    map<ll,ll> mm;

    REP(i,n+1){
        ans += mm[csum[i]];
        mm[csum[i]]++;
    }

    cout << ans << endl;
    return 0;
}