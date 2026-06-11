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
int n,c;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>c;

    if(n==1){
        //n=1のグリッドは常に条件を満たしている
        cout << "0" << endl;
        return 0;
    }
    vector<vi> d(c, vi(c,0));
    vector<vi> g(n, vi(n,0));

    map<int,int> lines[3];
    int sz=3;

    REP(i,c) REP(j,c){
        cin>>d[i][j];
    }

    REP(i,n) REP(j,n){
        cin>>g[i][j];
        lines[ (i+j) % 3 ][ g[i][j] ] += 1;
    }

    ll ans = LINF;
    FOR(c1, 1, c+1)
    FOR(c2, c1+1, c+1)
    FOR(c3, c2+1, c+1)
    {
        vi cls = {c1, c2 , c3}; //lines[i]をcls[i]の色に塗り替える
        do{
            ll tmp = 0;
            REP(i,sz){
                for(auto e:lines[i]){
                    tmp += d[e.first-1][cls[i]-1] * e.second;
                }
            }
            ans = min(ans,tmp);
        }while( next_permutation(ALL(cls)) );
    }

    cout << ans << endl;
    return 0;
}