#include<bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define eb emplace_back
#define endl '\n'
#define INF INT_MAX
#define nl cout << endl;
#define sz(a) (a).size()
#define len(a) (a).length()
#define all(v)  v.begin(),v.end()
#define set(v)  memset(v, 0, sizeof(v));
#define some(v, x) v.begin(), v.begin()+x
#define RANGET(i,a) for(ll i=0; i<a; ++i)
#define RANGE(i,a,b) for(ll i=a; i<b; ++i)
#define RANGEI(i,a,b,inc) for(ll i=a; i<b; i+=inc)
#define RANGER(i,a,b) for(ll i=a; i>=b; --i)
#define TEST_CASES(a) int t;if(a==1){t=1;}else{cin>>t;}while(t--)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define level 18
#define MAXN 1000001
#define MOD 1000000007

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<pair<int, int>> vpi;
typedef vector<pair<ll, ll>> vpl;
typedef vector<vpl> vvpl;

namespace io {
inline int rdi() { int v; cin >> v; return v; }
inline long long rdll() { long long v; cin >> v; return v;}
inline string rds() { string s; cin >> s; return s; }
inline char rdc() { char c; cin >> c; return c; }
template<class T>
void rdv(T beg_iter, T end_iter) {
    for (; beg_iter != end_iter; ++beg_iter)cin >> *beg_iter;
}
inline void wri(const int v) { cout << v; }
inline void wrll(const long long &v) { cout << v; }
inline void wrs(const string& s) { cout << s; }
inline void wrc(const char c) { cout << c; }
template<class T>
void wrv(T beg_iter, T end_iter, string separator = " ", string end_of_line = "\n") {
    for (; beg_iter != end_iter; ++beg_iter) {
        cout << *beg_iter;
        cout << separator;
    }
    cout << end_of_line;
}
}
using namespace io;

bool sortbysec(const pair<ll, ll> &a, const pair<ll, ll> &b) {return (a.second < b.second);}

ll binpow(ll a, ll b, ll m) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
string path = "DLRU";
vi di = {1, 0, 0, -1};
vi dj = {0, -1, 1, 0};

void solve();

int main()
{
    fast_io;

    TEST_CASES(1) solve();

    return 0;
}

void solve()
{
    //Adjust t
    int n;
    cin >> n;

    vvl A(n, vl(3));

    RANGET(i, n)
    rdv(all(A[i]));

    RANGE(i, 1, n)
    {
        A[i][0] += max(A[i - 1][1], A[i - 1][2]);
        A[i][1] += max(A[i - 1][0], A[i - 1][2]);
        A[i][2] += max(A[i - 1][0], A[i - 1][1]);
    }

    cout << max(A[n - 1][0], max(A[n - 1][1], A[n - 1][2])) << endl;
}