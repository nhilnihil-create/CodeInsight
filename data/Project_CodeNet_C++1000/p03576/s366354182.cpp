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


template<typename T>
void DEBUG_VEC2(vector<vector<T>> &v, int ilen, int jlen){
    REP(i,ilen){
        REP(j,jlen) if(v[i][j] != -1){ printf("[% 4d]", v[i][j]); }else{ printf("[    ]"); }
        puts("");
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,k;
    cin>>n>>k;
    vi x(n), y(n);
    vector<pii> xy(n);
    REP(i,n){
        cin>>x[i]>>y[i];
        xy[i] = pii(x[i],y[i]);
    }

    sort(ALL(x));
    sort(ALL(y));
    x.erase(unique(ALL(x)), x.end());
    y.erase(unique(ALL(y)), y.end());
    int szx = x.size();
    int szy = y.size();

    vector<vi> cs(szx+2, vi(szy+2,0));
    FOR(i,1,szx+1) FOR(j,1,szy+1){//x,y
        bool found = false;
        REP(k,n){
            if(xy[k].first == x[i-1]  &&  xy[k].second == y[j-1]){
                found=true;
                break;
            }
        }

        if(found){
            cs[i][j]++;
        }

        cs[i][j] += cs[i-1][j] + cs[i][j-1] - cs[i-1][j-1];
    }

    ll ans = LINF;

    REP(x1,szx) REP(y1,szy){
        FOR(x2,x1+1,szx) FOR(y2,y1+1,szy){
           int cntdot = ( cs[x2+1][y2+1] - cs[x2+1][y1] )  -  ( cs[x1][y2+1] - cs[x1][y1] );

           if(cntdot>=k){
               ll tate = (ll)y[y2]-(ll)y[y1];
               ll yoko = (ll)x[x2]-(ll)x[x1];
               chmin(ans,tate*yoko);
           }
        }
    }
    cout << ans << endl;
    return 0;
}