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

// Sieve of Eratosthenes
vi get_primes(int input) {
    int N = max(input, 100);

    vb Alive(N, true);
    Alive.at(0) = false;
    Alive.at(1) = false;

    // i番目の素数が分かる (0-origin)
    vi Ps;

    FORE(smallest, 2, (int)(sqrt(N)+1)) {
        if (!Alive.at(smallest)) {
            continue;
        }

        for(int i = smallest * 2; i < N; i += smallest) {
            Alive.at(i) = false;
        }
    }

    REP(i, N) {
        if (Alive.at(i)) {
            Ps.pb(i);
        }
    }

    return Ps;
}

bool is_like_2017(mib is_prime_map, int N) {
    if (!is_prime_map.count(N)) {
        return false;
    }

    if (!is_prime_map.count((N+1) / 2)) {
        return false;
    }

    return true;
}

signed main() {
    int Q;
    cin >> Q;

    int N = (int)1e5 + 1;

    vector<int> Ls(Q);
    vector<int> Rs(Q);
    REP(i, Q) {
        cin >> Ls.at(i) >> Rs.at(i);
    }

    vi primes = get_primes(N);
    mib is_prime_map;

    for(auto p : primes) {
        is_prime_map[p] = true;
    }

    mib like_2017_map;
    for(auto p : primes) {
        if (p != 2 && is_prime_map.count((p + 1) / 2)) {
            like_2017_map[p] = true;
        }
    }

    // 累積和を求めておく
    vi Acc(N);
    Acc.at(0) = 0;

    int sum = 0;
    FORE(i, 1, N-1){
        if (i % 2 == 0) {
            Acc.at(i) = Acc.at(i-1);
            continue;
        }

        sum += like_2017_map.count(i) ? 1 : 0;
        Acc.at(i) = sum;
    }

    REP(i, Q) {
        int l = Ls.at(i);
        int r = Rs.at(i);

        int ans;
        if (l == 0) {
            ans = Acc.at(r);
        } else {
            ans = Acc.at(r) - Acc.at(l-1);
        }
        cout << ans << endl;
    }

}
