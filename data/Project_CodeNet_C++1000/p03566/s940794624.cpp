#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll,ll> lll;

const ll MOD = 1000000007;
const ll INF = 1e9+5;
const double eps = 1e-7;
const double PI = acos(-1.0);

#define FOR(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RFOR(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define ull unsigned long long
#define deb(x )     cerr << #x << " = "<< x << endl;
#define endl    "\n"
#define coud(a,d) cout << fixed << showpoint << setprecision(d) << a;
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fill(x, y) memset(x, y, sizeof(y))
#define all(x) (x).begin(), (x).end()
#define bitcount(x) __builtin_popcount(x)
#define cps CLOCKS_PER_SEC
#define verify(x) if(x >= MOD) x -= MOD;

inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void print_case(int tn) {cout<<"Case #"<<tn<<": ";}

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
using maxpq = priority_queue<T>;
/*----------------------------------------------------------------------*/

const int nax = 101;
vi t,v;
int n, totalt;
vector<iii> intervals;
double speed[nax * 200 * 100 * 2];

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin>>n; t.resize(n); v.resize(n);
    FOR(i, 0, n) {
        cin>>t[i]; t[i] *= 2;
        totalt += t[i];
    }
    FOR(i, 0, totalt + 1) {
        speed[i] = INF;
    }
    FOR(i, 0, n) cin>>v[i];
    intervals.push_back({0, {0, 0}});
    int csum = 0;
    FOR(i, 0, n) {
        intervals.push_back({v[i], {csum, csum + t[i]}});
        csum += t[i];
    }
    intervals.push_back({0, {totalt, totalt}});

    int l,r,sp;
    FOR(i, 0, intervals.size()) {
        sp = intervals[i].first;
        tie(l, r) = intervals[i].second;

        // cerr << l << " " << r << " " << sp << endl;

        FOR(ts, l, r + 1) {
            speed[ts] = min(speed[ts], 1.0 * sp);
        }
        FOR(ts, 0, l + 1) {
            speed[ts] = min(speed[ts], sp + (l - ts)/2.0);
        }
        FOR(ts, r, totalt + 1) {
            speed[ts] = min(speed[ts], sp + (ts - r)/2.0);
        }
    }

    long double res = 0;

    FOR(ts, 0, totalt) {
        res += 0.5 * (speed[ts] + speed[ts + 1]);
    }
    
    res /= 2;
    coud(res, 12);

    return 0;
}