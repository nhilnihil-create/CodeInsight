#include <bits/stdc++.h>
using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> P;
typedef long long ll;

#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define SORT(c) sort((c).begin(),(c).end())
#define REVERSE(c) reverse((c).begin(),(c).end())

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);--i)
#define RREP(i,n) RFOR(i,n,0)

const double EPS = 1e-10;
const double PI  = acos(-1.0);
const int INT_INF = 2147483647;
const long long LL_INF = 1LL<<60;
const long long MOD = 1000000007;

#define CLR(a) memset((a), 0 ,sizeof(a))

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

template<typename T>
struct BIT{
    private:
        using Func = function<T(T, T)>;

        int n;
        vector<T> node;

        T init_v;
        Func func;

    public:

        BIT(vector<T> a, Func _func, T _init_v) {
            n = a.size() + 1;
            init_v = _init_v;
            func = _func;

            node.resize(n, init_v);
            for(int i=1; i<n; i++) if((i+(i&-i)) < n) node[i+(i&-i)] = func(node[i+(i&-i)], node[i]);
        }

        BIT() {}

        void add(int pos, T v) {
            while(pos < n){
                node[pos] = func(node[pos], v);
                pos += pos & -pos;
            }
        }

        T sum(int pos){
            T res = init_v;
            while(pos > 0){
                res = func(res, node[pos]);
                pos = pos & (pos-1);
            }
            return res;
        }
};

int func(int a, int b){
    return a+b;
}

int main(void){
    string s,s2; cin >> s;
    REP(i,s.size()){
        if(i<s.size()-1 && s[i]=='B' && s[i+1]=='C'){
            s2 += 'D';
            i++;
        }
        else s2 += s[i];
    }
    swap(s2,s);
    
    ll ans = 0;
    REP(i,s.size()){
        int nA = 0;
        while(i<s.size() && (s[i]=='A'||s[i]=='D')){
            if(s[i]=='A') nA++;
            else ans += nA;
            i++;
        }
    }

    cout << ans << endl;
    return 0;
}