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

template<class T>
void remove_duplication(vector<T> &v){
    sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
}

void Main(){
    int N,K,Q; cin >> N >> K >> Q;
    VI A(N); REP(i,N) cin >> A[i];
    VI B(A); remove_duplication(B);

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