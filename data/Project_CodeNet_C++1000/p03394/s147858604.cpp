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

int main(void){
    int N; cin >> N;
    set<int> ans;
    if(N == 3) ans = set<int>{2,5,63};
    else if(N == 4) ans = set<int>{2,5,20,63};
    else if(N == 5) ans = set<int>{2,5,20,30,63};
    else{
        int sum = 0;
        FOR(i,1,30001){
            if(i%6==0||i%6==2||i%6==3||i%6==4){
                ans.insert(i);
                sum += i;
            }
            if(ans.size() == N) break;
        }
        int last = *ans.rbegin()+1;
        if(sum%6 == 2){
            ans.erase(8);
            while(last%6 != 0) last++;
            ans.insert(last);
        }
        else if(sum%6 == 3){
            ans.erase(9);
            while(last%6 != 0) last++;
            ans.insert(last);
        }
        else if(sum%6 == 5){
            ans.erase(9);
            while(last%6 != 4) last++;
            ans.insert(last);
        }
    }

    for(int n : ans){
        cout << n << " ";
    }
    cout << endl;
    return 0;
}
