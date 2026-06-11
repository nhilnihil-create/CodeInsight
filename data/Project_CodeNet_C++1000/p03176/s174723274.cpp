const int isDebugMode = 1;
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long long, long long> P;
struct edge{long long to,cost;};
const int inf = 1 << 27;
const long long INF = 1LL << 60;
const int COMBMAX = 1001001;
const long long MOD = 1000000007;
const long long dy[] = {-1, 0, 0, 1};
const long long dx[] = {0, -1, 1, 0};
string abc = "abcdefghijklmnopqrstuvwxyz";
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define eachdo(v, e) for (const auto &e : (v))
#define all(v) (v).begin(), (v).end()
#define lower_index(v, e) (long long)distance((v).begin(), lower_bound((v).begin(), (v).end(), e))
#define upper_index(v, e) (long long)distance((v).begin(), upper_bound((v).begin(), (v).end(), e))
long long mpow(long long a, long long n, long long mod = MOD){long long res = 1; while(n > 0){if(n & 1)res = res * a % mod; a = a * a % mod; n >>= 1;} return res;}
void pt(){cout << endl; return;}
template<class Head> void pt(Head&& head){cout << head; pt(); return;}
template<class Head, class... Tail> void pt(Head&& head, Tail&&... tail){cout << head << " "; pt(forward<Tail>(tail)...);}
void dpt(){if(!isDebugMode) return; cout << endl; return;}
template<class Head> void dpt(Head&& head){if(!isDebugMode) return; cout << head; pt(); return;}
template<class Head, class... Tail> void dpt(Head&& head, Tail&&... tail){if(!isDebugMode) return; cout << head << " "; pt(forward<Tail>(tail)...);}
template<class T> void debug(T v){if(!isDebugMode) return; rep(i, v.size()) cout << v[i] << " " ; cout << endl;}
template<class T> void debug2(T v){if(!isDebugMode) return; rep(i, v.size()){rep(j, v[i].size()) cout << v[i][j] << " " ; cout << endl;}}
template<class T1, class T2> inline bool chmin(T1 &a, T2 b){if(a > b){a = b; return true;} return false;}
template<class T1, class T2> inline bool chmax(T1 &a, T2 b){if(a < b){a = b; return true;} return false;}
template<class T1, class T2> long long recgcd(T1 a, T2 b){return a % b ? recgcd(b , a % b) : b;}
bool valid(long long H, long long W, long long h, long long w) { return 0 <= h && h < H && 0 <= w && w < W; }

struct SegmentTree{
private:
    ll unit = 0;
    ll op(ll a,ll b){return max(a, b);}
    ll n;
    vector<ll> node;

public:
SegmentTree(vector<ll> v){
    ll sz = (ll)v.size();
    n = 1;while(n<sz) n *= 2;
    node.resize(2*n-1,unit);
    for(ll i=0;i<sz;i++) node[i+n-1]=v[i];
    for(ll i=n-2;i>=0;i--) node[i]=op(node[2*i+1],node[2*i+2]);
}

    void update(ll x,ll val){
        x += n-1;
        node[x] = val;
        while(x>0){
            x = (x-1)/2;
            node[x] = op(node[2*x+1],node[2*x+2]);
        }
    }

    ll query(ll a,ll b,ll k = 0,ll l = 0,ll r = -1){
        if (r<0) r = n;
        if (r<=a || b<=l) return unit;
        if (a<=l && r<=b) return node[k];
        ll vl = query(a,b,2*k+1,l,(l+r)/2);
        ll vr = query(a,b,2*k+2,(l+r)/2,r);
        return op(vl,vr);
    }
};

int main(){
    ll N; cin >> N;
    vector<ll> h(N), a(N);
    rep(i, N) cin >> h[i];
    rep(i, N) cin >> a[i];
    SegmentTree dp(vector<ll>(N + 1, 0));
    rep(i, N){
        dp.update(h[i], dp.query(0, h[i]) + a[i]);
    }
    pt(dp.query(0, N + 1));
    return 0;
}