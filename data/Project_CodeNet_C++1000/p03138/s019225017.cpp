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
    ll n,k;
    cin>>n>>k;
    vl a(n);
    const int DMX = 40;
    vector<vl> digitcnt(2,vl(DMX,0)); //[0 or 1][桁] = 個数
    REP(i,n){
        cin>>a[i];
        REP(j,DMX){
            //if(a[i] >= (1LL<<j))
                digitcnt[(a[i]>>j) & 1][j]++;
        }
    }

    //DEBUG_VEC(digitcnt[0]);
    //DEBUG_VEC(digitcnt[1]);

    ll x=0;
    FORR(i,0,DMX){
        ll dval = 1LL<<i;
        //DEBUG2(i, dval);
        //0を置くことを優先する
        if(digitcnt[0][i] > digitcnt[1][i] && (x | dval) <= k){
            x += dval;
        }
        //DEBUG(x);
    }

    ll ans=0;
    REP(i,n) ans+=a[i]^x;

    cout << ans << endl;
    return 0;
}