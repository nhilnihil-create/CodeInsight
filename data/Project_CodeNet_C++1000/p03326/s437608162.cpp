#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<vector>
#include<utility>
#include<queue>
#include<deque>
#include<stack>
#include<set>
#include<map>
#include<bitset>
#include<string>
#include<functional>
#define rep(i,n,m) for(int i=(n);i<(int)(m);i++)
#define reps(i,n,m) for(int i=(n);i<=(int)(m);i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define SZ(x) ((int)(x).size())
#define pb push_back
#define fs first
#define sc second
#define lb lower_bound
#define ub upper_bound
#define LB(a,x) lb(all(a), x) - a.begin()
#define UB(a,x) ub(all(a), x) - a.begin()
#define printfdouble(x) printf("%.12f\n",(x))
#define chartoint(c) (int)((c) - '0')
#define chartoll(c) (long long)((c) - '0')
#define MOD 1000000007
#define itn int
#define enld endl
#define ednl endl
#define icn cin
#define Endl endl
#define stirng string
using namespace std;
typedef long long ll;
const double pi = 3.141592653589793;
using Graph = vector<vector<int>>;
template<class T> bool chmax(T &a, const T &b){if(a<b){a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b){if(b<a){a=b; return 1;} return 0;}
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    ll N,M; cin >> N >> M;
    ll x[1005],y[1005],z[1005];
    rep(i,0,N) cin >> x[i] >> y[i] >> z[i];
    ll ans = 0;
    rep(i,0,(1<<3)){
        vector<ll> v;
        rep(j,0,N){
            ll tmp = 0;
            if(1<<0 & i) tmp += x[j];
            else tmp -= x[j];
            if(1<<1 & i) tmp += y[j];
            else tmp -= y[j];
            if(1<<2 & i) tmp += z[j];
            else tmp -= z[j];
            v.pb(tmp);
        }
        sort(allr(v));
        ll tmp2 = 0;
        rep(i,0,M) tmp2 += v[i];
        chmax(ans, tmp2);
    }

    cout << ans << ednl;
    return 0;
}
