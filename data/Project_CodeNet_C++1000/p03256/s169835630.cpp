#include <bits/stdc++.h>
#define REP(i,n) for (long long i=0;i<(n);i++)
#define FOR(i,a,b) for (long long i=(a);i<(b);i++)
#define RREP(i,n) for(long long i=n;i>=0;i--)
#define RFOR(i,a,b) for(long long i=(a);i>(b);i--)
#define dump1d_arr(array) REP(i,array.size()) cerr << #array << "[" << (i) << "] ==> " << (array[i]) << endl
#define dump2d_arr(array) REP(i,array.size()) REP(j,array[i].size()) cerr << #array << "[" << (i) << "]" << "[" << (j) << "] ==> " << (array[i][j]) << endl
#define dump(x)  cerr << #x << " => " << (x) << endl
#define dumpP(p) cerr << "( " << p.first << " , " << p.second << " )" << ends
#define SORT(c) sort((c).begin(),(c).end())
#define MIN(vec) *min_element(vec.begin(), vec.end())
#define MAX(vec) *max_element(vec.begin(), vec.end())
#define UNIQ(vec) vec.erase(unique(vec.begin(), vec.end()),vec.end()) //ソートの必要あり
#define IN(n,m)  (!(m.find(n) == m.end()))
#define ENUM(m) for (auto itr = m.begin(); itr != m.end(); ++itr)
#define dump_MAP(m) for(auto itr = m.begin(); itr != m.end(); ++itr) { cerr << itr->first << " --> "  << itr->second << endl; }
#define FINDL(vec,x) (lower_bound(vec.begin(),vec.end(),x) - vec.begin())
#define FINDU(vec,x) (upper_bound(vec.begin(),vec.end(),x) - vec.begin())
#define ROUND(N) setprecision(N)
#define ROUND_PRINT(N,val) cout << fixed;cout << setprecision(N) << val << endl
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define INARR(h,w,x,y) (0 <= y && y < h && 0 <= x && x < w)
#define EQ(a,b) (abs(a - b) < 1e-10)
using namespace std;
constexpr int dx[4] = {0,1,0,-1};
constexpr int dy[4] = {1,0,-1,0};
constexpr long double pi = M_PI;
constexpr double eps = 1e-10;
constexpr long mod = 1000000007;
constexpr short shINF = 32767;
constexpr long loINF = 2147483647;
constexpr long long llINF = 9223372036854775807;
typedef long long LL;
typedef vector<LL> VL;
typedef vector<VL> VVL;
typedef vector<int> VI;
typedef vector<VI>  VVI;
typedef vector<string> VS;
typedef pair<LL,LL> pr;
typedef vector<bool> VB;
typedef vector<pr> VP;
typedef priority_queue<pr,vector<pr>,greater<pr>> pq;

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    long N,M,a,b;
    cin >> N >> M;
    string s;
    cin >> s;
    vector<set<long>> E(N);
    vector<int> removed(N,0);
    REP(i,M) {
        cin >> a >> b;
        E[a-1].insert(b-1);
        E[b-1].insert(a-1);
    }
    VI A(N,0),B(N,0);
    queue<long> que;
    REP(i,N) {
        for (int nx : E[i]) {
            if (s[nx] == 'A') A[i]++;
            else B[i]++;
        }
        if (A[i] == 0 || B[i] == 0) {
            que.push(i);
            removed[i] = 1;
        }
    }


    long node = N;
    while (!que.empty()) {
        long cur = que.front();que.pop();
        node--;
        for (int nx : E[cur]) {
            if (nx != cur && removed[nx] == 0) {
                if (s[cur] == 'A') A[nx]--;
                else if (s[cur] == 'B') B[nx]--;
                if (A[nx] == 0 || B[nx] == 0) {
                    que.push(nx);
                    removed[nx] = 1;
                }
            }
        }
    }
    if (node >= 1) cout << "Yes" <<  endl;
    else cout << "No" << endl;

}



