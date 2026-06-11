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
#define VOUT(v, sep) for(_loop_int idx=0; idx<(_loop_int)v.size(); idx++) {cout<<v[idx]; if(idx<(_loop_int)v.size()-1) cout<<sep;} cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG2(x,y) cout<<#x<<": "<<x<<" "<<#y<<": "<<y<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(debugidx,v.size())cout<<" "<<v[debugidx];cout<<endl
#define DEBUG_ARR(v,n) cout<<#v<<":";REP(debugidx,n)cout<<" "<<v[debugidx];cout<<endl

const ll MOD = 1000000007ll;
const int IINF = numeric_limits<int>::max()/2-1;
const ll LINF = numeric_limits<ll>::max()/2-1;

template<class T> inline bool chmin(T& a, const T b) { if (a>b) { a=b; return true; } return false; }
template<class T> inline bool chmax(T& a, const T b) { if (a<b) { a=b; return true; } return false; }



int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,k;
    cin>>n>>k;
    vl v(n);
    REP(i,n)
        cin>>v[i];

    ll ans = 0;
    REP(l, min(n+1, k+1)){
        REP(r, min(n+1, k+1-l)){
            ll tmp = 0;
            priority_queue<ll, vector<ll>, greater<ll>> minus;

            //DEBUG2(l,r);

            //左からL個
            REP(i,l){
                tmp += v[i];
                if(v[i]<0)
                    minus.emplace(v[i]);
            }
            //右からR個
            REP(i,r){
                if(n-i==l){
                    break;
                }
                tmp += v[n-1-i];
                //DEBUG(v[n-1-i]);
                if(v[n-1-i]<0)
                    minus.emplace(v[n-1-i]);
            }
            //DEBUG(tmp);
            int remain = k-l-r;

            while(!minus.empty() && remain>0){
                auto e = minus.top();
                minus.pop();
                //DEBUG(e);
                tmp -= e;
                remain--;
            }

            chmax(ans, tmp);
        }
    }


    cout << ans << endl;
    return 0;
}