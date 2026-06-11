#include <bits/stdc++.h>
#define fi first
#define se second
#define REP(i, a, b) for (int i = (a); i <= (b); ++i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORD(i, a, b) for(int i = (a); i > (b); --i)
#define REPD(i, a, b) for(int i = (a); i >=(b); --i)
#define TR(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define endl '\n'
#define mp make_pair
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define ins insert
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define unmap unordered_map
#define pq priority_queue
#define minEle min_element
#define maxEle max_element
#define lb lower_bound //first pos >= val
#define ub upper_bound // first pos > val
#define bp __builtin_popcount
#define debug(a) cout << a << endl
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;
typedef pair <pii, int> ppi;
typedef pair <int, pii> pip;
typedef pair <ll, ld> pld;
typedef pair <ll, pll> pllp;
typedef pair <pll, ll> ppll;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <pll> vpll;
typedef vector <pii> vpii;
typedef map <int, int> mii;
typedef map <ll, ll> mll;
typedef string BigNum;

const ll maxN = 1e18;
const ll minN = -1e18;
const ll MOD = 1e9 + 7;
const ll MOD1 = 998244353;
const int baseHash = 331;
const int bigNumLength = 5000;
const ld PI = acos(-1);

//Remember limit for IT, etc..., and +1 in limit of any array
const ll limit = 2e5 + 5;
const ll limit1 = 2e6 + 5;
const ll limit2 = 1e3 + 5;
//If TLE let's use int instead of ll because it's as slow as your WPM :)))

/*----IMPORTANT THINGS----*/
pii dir[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
//right down left up rightdown leftdown rightup leftup
pii NON = {-1, -1};
/*------------------------*/

ll n;
ll a[25][25];
ll f[limit1 + 100000][22];

int onBit(int msk, int k) {
    return msk | (1 << k);
}

int offBit(int msk, int k) {
    return msk & ( ~ (1 << k));
}

int getBit(int msk, int k) {
    return (msk >> k) & 1;
}

int flipBit(int msk, int k) {
    return (msk ^ (1 << k));
}

void solveProblem() {
    //f[msk][i]: num of ways to create a state msk with the last couple is a[i][numBit(msk)] (when bit is is on && a[][] is 1)
    REP(msk, 0, (1 << n) - 1) {
        int num = bp(msk);
        REP(i, 1, n) {
            if (getBit(msk, n - i) == 1) {
                int t = flipBit(msk, n - i);
                if (num == 1) {f[msk][i] = a[i][num]; break;}
                REP(j, 1, n) {
                    if (getBit(msk, n - j) == 1 && j != i && a[i][num]) {
                        f[msk][i] = (f[msk][i] + f[t][j]) % MOD;
                    }
                }
            }
        }
    }

    ll ans = 0;
    REP(i, 1, n) ans = (ans + f[(1 << n) - 1][i]) % MOD;

    cout << ans << endl;
}

void fastInput() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void readInput() {
    cin >> n;
    REP(i, 1, n) {
        REP(j, 1, n) {
            cin >> a[i][j];
        }
    }
}

int main() {
    fastInput();
    readInput();
    solveProblem();
}

