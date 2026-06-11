#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<long long> VL;
typedef vector<vector<long long>> VVL;
typedef pair<int,int> P;
typedef tuple<int,int,int> tpl;

#define ALL(a)  (a).begin(),(a).end()
#define SORT(c) sort((c).begin(),(c).end())
#define REVERSE(c) reverse((c).begin(),(c).end())
#define EXIST(m,v) (m).find((v)) != (m).end()
#define LB(a,x) lower_bound((a).begin(), (a).end(), x) - (a).begin()
#define UB(a,x) upper_bound((a).begin(), (a).end(), x) - (a).begin()

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);--i)
#define RREP(i,n) RFOR(i,n,0)

#define en 


constexpr double EPS = 1e-9;
constexpr double PI  = 3.1415926535897932;
constexpr int INF = 2147483647;
constexpr long long LINF = 1LL<<60;
constexpr long long MOD = 1000000007;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }


void Main() {
    int h, w;
    cin >> h >> w;
    vector<string> sv(h);
    REP(i, h) {
        string s;
        cin >> s;
        sv[i] = s;
    }
    queue<int> que;
    que.push(0);
    VI ansv(h*w, -1);
    ansv[0] = 0;
    while(!que.empty()) {
        int v = que.front();
        que.pop();
        if (v % w != 0) {
            if(sv[v/w][(v-1)%w] != '#' && ansv[v-1] == -1) {
                ansv[v-1] = ansv[v] + 1;
                que.push(v-1);
            }
        }
        if (v % w != w-1) {
            if(sv[v/w][(v+1)%w] != '#' && ansv[v+1] == -1) {
                ansv[v+1] = ansv[v] + 1;
                que.push(v+1);
            }
        }
        if (v / w != 0) {
            if(sv[v/w-1][v%w] != '#' && ansv[v-w] == -1) {
                ansv[v-w] = ansv[v] + 1;
                que.push(v-w);
            }
        }
        if (v / w != h-1) {
            if(sv[v/w+1][v%w] != '#' && ansv[v+w] == -1) {
                ansv[v+w] = ansv[v] + 1;
                que.push(v+w);
            }
        }
    }
    int count = 0;
    REP(i, h) {
        REP(j, w) {
            if (sv[i][j] == '.') {
                count++;
            }
        }
    }
    if (ansv[w*h-1] == -1) {
        cout << -1 << endl;
    } else {
        cout << count - ansv[w*h-1]-1 << endl;
    }
}

int main(void){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);cout<<fixed<<setprecision(15);
    int t=1; //cin>>t;
    REP(_,t) Main();
    return 0;
}

