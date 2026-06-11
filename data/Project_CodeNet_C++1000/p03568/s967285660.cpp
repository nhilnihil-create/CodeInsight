#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define REPr(i, n) for(int i = (n)-1; i >= 0; --i)
#define FORq(i, m, n) for(int i = (m); i <= (n); ++i)
#define FORqr(i, m, n) for(int i = (n); i >= (m); --i)
#define MP make_pair
#define SIN(x, S) (S.count(x) != 0)
#define M0(x) memset(x, 0, sizeof(x))
#define FILL(x, y) memset(x, y, sizeof(x))
#define MM(x) memset(x, -1, sizeof(x))
#define ALL(x) (x).begin(), (x).end()
#define DB(x) cerr << #x << " = " << x << endl
#define DB2(x, y)                                                              \
    cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define DEBUG                                                                  \
    int x12345;                                                                \
    cin >> x12345;
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<long long> VL;
typedef long long ll;
typedef long long integer;
///////////////////////////////////////////////
const long long MOD = 1e9 + 7;
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

///////////////////////////////////////////////
/// 🍈( '-' 🍈 |AC|
int main() {
    bool ok = true;
	int N;
	cin >> N;
	vector<int> A(N);
	REP(i,N){
		cin >> A[i];
	}

	ll all = 1;
	FORq(i,1,N){
		all *= 3;
	}

	ll minus = 1;
	REP(i,N){
		if (A[i] % 2 == 0) minus *= 2;
	}

	cout << all - minus << endl;
}