#include <bits/stdc++.h>
using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<long long> VL;
typedef vector<vector<long long>> VVL;
typedef vector<string> VS;
typedef pair<int, int> P;
typedef tuple<int,int,int> tpl;

#define ALL(a)  (a).begin(),(a).end()
#define SORT(c) sort((c).begin(),(c).end())
#define REVERSE(c) reverse((c).begin(),(c).end())
#define LB(a,x) lower_bound((a).begin(), (a).end(), x) - (a).begin()
#define UB(a,x) upper_bound((a).begin(), (a).end(), x) - (a).begin()

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);--i)
#define RREP(i,n) RFOR(i,n,0)

#define en "\n"

constexpr double EPS = 1e-9;
constexpr double PI  = 3.1415926535897932;
constexpr int INF = 2147483647;
constexpr long long LINF = 1LL<<60;
constexpr long long MOD = 1000000007; // 998244353;

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

template<typename T>
struct SegmentTree {
	typedef function<T(T,T)> F;
    typedef function<T(T,T)> G;
    int n;
    F f;
    G g;
    T e;

    vector<T> val;

    SegmentTree(vector<T> a, F f_, G g_, T e):
        f(f_), g(g_), e(e){
            int sz = a.size();
            n = 1;

            while (n < sz) n <<= 1;
            val.resize(2 * n - 1, e);
            for (int i = 0; i < sz; i++) val[i + n - 1] = a[i];
            for (int i = n - 2; i >= 0; i--) val[i] = f(val[i * 2 + 1], val[i * 2 + 2]);
        }
    
        SegmentTree() {}

        void update(int pos, T v) {
            // 0-indexed
            int k = pos + n - 1;
            val[k] = g(val[k], v);
            while (k > 0) {
                k = (k - 1) / 2;
                val[k] = f(val[k * 2 + 1], val[k * 2 + 2]);
            }
        }

        T get(int pos) {
            // 0-indexed
            int k = pos + n - 1;
            return val[k];
        }

        T query(int a, int b, int k = 0, int l = 0, int r = -1) {
            // 0-indexed
            // [a,b)に対してquery
            if (r < 0) r = n;
            if (r <= a || b <= l) return e;
            if (a <= l && r <= b) return val[k];
            T lv = query(a, b, k * 2 + 1, l, (l + r) / 2);
            T rv = query(a, b, k * 2 + 2, (l + r) / 2, r);
            return f(lv, rv);
        }
};

template<class T>
void remove_duplication(vector<T> &v){
    sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
}

void Main(){
    int N,K,Q; cin >> N >> K >> Q;
    VI A(N); REP(i,N) cin >> A[i];
    VI B(A); remove_duplication(B);

    SegmentTree<int> st(A,[](int a,int b){return min(a,b);},[](int a,int b){return b;},INF);

    int ans = INF;
    REP(i,(int)B.size()){
        int ptr = 0;
        VI q;
        while(ptr<N-K+1){
            if(A[ptr] < B[i]){
                ptr++;
                continue;
            }

            int l = ptr, r = l+1;
            while(r<N && A[r]>=B[i]) r++;

            if(r-l < K){
                ptr = r;
                continue;
            }

            VI cand;
            FOR(j,ptr,r) cand.push_back(A[j]);
            SORT(cand);
            REP(j,r-l-K+1) q.push_back(cand[j]);

            ptr = r;
        }

        if(q.size() < Q) break;
        SORT(q);
        chmin(ans, q[Q-1] - q[0]);
    }

    cout << ans << en;
    return;
}

int main(void){
    cin.tie(0);ios_base::sync_with_stdio(0);cout<<fixed<<setprecision(15);
    int t=1; //cin>>t;
    REP(_,t){
        Main();
    }
    return 0;
}