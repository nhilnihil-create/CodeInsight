#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;

typedef int _loop_int;
#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG2(x,y) cout<<#x<<": "<<x<<" "<<#y<<": "<<y<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define DEBUG_ARR(v,n) cout<<#v<<":";REP(i,n)cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

const ll MOD = 1000000007ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin>>n;
    vi a(n);
    REP(i,n) cin>>a[i];

    vl cs(n+1);
    unordered_map<ll,ll> cnt;
    ll ans = 0;
    cnt[0] = 1;
    ll zero = 0;
    REP(i,n){
        cs[i+1] = cs[i]+a[i];
        cnt[cs[i+1]]++;
    }

    for(auto& e : cnt){
        //DEBUG2(e.first, e.second);
        ans += (e.second * (e.second-1)) / 2LL;
    }

    cout << ans << endl;
    return 0;
}