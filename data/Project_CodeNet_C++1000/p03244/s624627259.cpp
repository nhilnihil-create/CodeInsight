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
    int n;
    cin>>n;
    vi v(n);

    const int N = 100005;
    //const int N = 150;
    vi odd(N,0);
    vi even(N,0);

    REP(i,n){
        int a;
        cin>>a;
        if(i%2==0){
            even[a]++;
        }else{
            odd[a]++;
        }
    }

    int mxo=-1;
    int mxe=-1;
    int oidx=0;
    int oidx2=0;
    int eidx=0;
    int eidx2=0;
  
    REP(i,N){
        if(chmax(mxe, even[i])){
            eidx2 = eidx;
            eidx = i;
        }else if(eidx2 == -1 || even[eidx2] < even[i]){
            eidx2 = i;
        }
        if(chmax(mxo, odd[i])){
            oidx2 = oidx;
            oidx = i;
        }else if(oidx2 == -1 || odd[oidx2] < odd[i]){
            oidx2 = i;
        }
    }

    int ans = 0;
    
    if(oidx != eidx){
        ans = n-odd[oidx]-even[eidx];
    }else if(odd[oidx2] > even[eidx2]){
        ans = n-odd[oidx2]-even[eidx];
    }else{
        ans = n-odd[oidx]-even[eidx2];
    }     

    cout << ans << endl;
    return 0;
}