#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll

typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> pii;
typedef vector<pair<int,int> > vpii;
typedef vector<vector<bool> > vvb;
typedef map<int, bool> mib;

typedef long long ll;
typedef vector<long long> vl;
typedef pair<long long,long long> pll;
typedef vector<pair<long long,long long> > vpll;

typedef vector<string> vs;

typedef long double ld;

#define _GLIBCXX_DEBUG

#define REP(i,n) for (int i = 0; i < (n); ++i)
#define REPD(i,n) for (int i = (n-1); i >= 0; --i)
#define FORE(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << '\n'
#define debug2(x, y) cerr << #x << ": " << x << ", " << #y << ": " << y << '\n'
#define debug3(x, y, z) cerr << #x << ": " << x << ", " << #y << ": " << y << ", " << #z << ": " << z << '\n'
#define hyphen() cerr << "--\n"

#define ALL(vec) (vec).begin(), (vec).end()
#define REVALL(vec) (vec).rbegin(), (vec).rend()

static const int dy[4] = {0,1,0,-1}, dx[4] = {1,0,-1,0};

#define fst first
#define snd second
#define pb push_back
#define mp(x,y) make_pair((x),(y))

const int MOD = (int)1e9 + 7;
const int INF = numeric_limits<int>::max();

signed main() {
    int N, Q;
    string S;

    cin >> N >> Q >> S;

    vector<int> Ls(Q);
    vector<int> Rs(Q);
    REP(i, Q) {
        cin >> Ls.at(i) >> Rs.at(i);
    }

    // Ss.at(i) = S.at(0) から S.at(i) まで (両端含む) にACが何回現れるか
    vi Ss(N);

    int sum = 0;
    bool prev_is_a = false;
    REP(i, N) {
        char ch = S.at(i);
        if (prev_is_a && ch == 'C') {
            sum += 1;
            Ss.at(i) = sum;
            prev_is_a = false;
        } else if (ch == 'A') {
            prev_is_a = true;
            Ss.at(i) = sum;
        } else {
            prev_is_a = false;
            Ss.at(i) = sum;
        }
    }

    REP(i, Q) {
        int l = Ls.at(i) - 1;
        int r = Rs.at(i) - 1;

        int ans = Ss.at(r) - Ss.at(l);
        cout << ans << endl;
    }


}
