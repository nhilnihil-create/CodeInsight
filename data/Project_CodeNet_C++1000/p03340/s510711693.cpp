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
#define DEBUG_VEC(v) cout<<#v<<":";REP(debugidx,v.size())cout<<" "<<v[debugidx];cout<<endl
#define DEBUG_ARR(v,n) cout<<#v<<":";REP(debugidx,n)cout<<" "<<v[debugidx];cout<<endl
#define ALL(a) (a).begin(),(a).end()

const ll MOD = 1000000007ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin>>n;
    vl a(n);
    REP(i,n) cin>>a[i];

    vl csx(n+1); //xor
    vl csp(n+1); //plus

    vl cs(n+1);
    csx[0] = 0;
    csp[0] = 0;

    REP(i,n){
        csx[i+1] = csx[i]^a[i];
        csp[i+1] = csp[i]+a[i];
    }
    //DEBUG_VEC(csx);
    //DEBUG_VEC(csp);

    ll ans=0;
    int lpos = 0;
    int rpos = n;
    for(;lpos < n; lpos++){
        rpos = n;

        {
            int ok = lpos, ng = n+1;
            while(abs(ok-ng) > 1){
                int mid = (ok+ng)/2;
                ll sumx = csx[mid] ^ csx[lpos];
                ll sump = csp[mid] - csp[lpos];
                if(sumx==sump){
                    ok = mid;
                }else{
                    ng = mid;
                }
            }

            rpos = ok;
            ans += rpos-lpos;
        }
    }

    cout << ans << endl;
    return 0;
}