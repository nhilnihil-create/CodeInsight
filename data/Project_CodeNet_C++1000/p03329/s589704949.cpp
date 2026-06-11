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

#define VIN(v) for(auto&elem_: (v) )cin>>elem_
#define VOUT(v, sep) for(_loop_int idx=0; idx<(_loop_int)v.size(); idx++) {cout<<v[idx]; if(idx<v.size()-1) cout<<sep;} cout<<endl

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG2(x,y) cout<<#x<<": "<<x<<" "<<#y<<": "<<y<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(debugidx,v.size())cout<<" "<<v[debugidx];cout<<endl
#define DEBUG_ARR(v,n) cout<<#v<<":";REP(debugidx,n)cout<<" "<<v[debugidx];cout<<endl
#define ALL(a) (a).begin(),(a).end()

const ll MOD = 1000000007ll;
const int IINF = numeric_limits<int>::max()/2-1;
const ll LINF = numeric_limits<ll>::max()/2-1;
#define FIX(a) ((a)%MOD+MOD)%MOD

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin>>n;

    if(n<6){
        cout<<n<<endl;
        return 0;
    }

    int q=0,r=0;//9,6
    int ans = IINF;

    while((9*q)<=n){
        r = (n-(9*q)) / 6;
        
        int m = 0;
        
        if(q+r > 0)
            m = n % (9*q+6*r);

        if(m < 6 && (9*q)+(6*r)+m==n){
            int cnt9 = 0;
            int cnt6 = 0;

            int tmp = q;
            FORR(i,1,6){ //9^5 = 59049
                cnt9 += tmp / (int)pow(9,i);
                tmp %= (int)pow(9,i);
            }
            cnt9 += tmp;

            tmp = r;
            FORR(i,1,7){ //6^6 = 46656
                cnt6 += tmp / (int)pow(6,i);
                tmp %= (int)pow(6,i);
            }
            cnt6 += tmp;

            ans = min(ans, cnt9+cnt6+m);
        }
        q++;
    }
    cout << ans << endl;
    return 0;
}