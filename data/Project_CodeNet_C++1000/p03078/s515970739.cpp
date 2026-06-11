#include "bits/stdc++.h"
 
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef long long LL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef vector<VVLL> VVVLL;
typedef pair<LL, LL> PLL;
typedef vector<PLL> VPLL;

#define SORT_ASC(c) sort((c).begin(), (c).end())
#define SORT_DESC(c) sort((c).begin(), (c).end(), greater<typeof((c).begin())>())
 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define FORL(i,a,b) for(LL i=(a);i<(b);++i)
#define REPL(i,n)  FORL(i,0,n)
#define SIZE(a) int((a).size())
#define ALL(a) (a).begin(),(a).end()
 
const double EPS = 1e-10;
const double PI  = acos(-1.0);

 //debug func
template<typename T>
void vprint(vector<T> v) {
    for(auto x : v) {
        cerr << x << " ";
    }
    cerr << endl;
}
 
template<typename T>
void vvprint(vector<vector<T>> vv) {
    REP(i, SIZE(vv)) {
        REP(j, SIZE(vv[i])) {
            cerr << vv[i][j] << " ";
        }
        cerr << endl;
    }
}

template<typename T1, typename T2>
void vpprint(vector<pair<T1, T2>> vp) {
    REP(i, SIZE(vp)) {
        cerr << vp[i].first << ", " << vp[i].second << endl;
    }
}

template<typename T1, typename T2>
void mprint(map<T1, T2> m) {
    for(auto x : m) cerr << x.first << ", " << x.second << endl;
}

template <typename Iterator>
inline bool next_combination(const Iterator first, Iterator k, const Iterator last)
{
   /* Credits: Thomas Draper */
   if ((first == last) || (first == k) || (last == k))
      return false;
   Iterator itr1 = first;
   Iterator itr2 = last;
   ++itr1;
   if (last == itr1)
      return false;
   itr1 = last;
   --itr1;
   itr1 = k;
   --itr2;
   while (first != itr1)
   {
      if (*--itr1 < *itr2)
      {
         Iterator j = k;
         while (!(*itr1 < *j)) ++j;
         iter_swap(itr1,j);
         ++itr1;
         ++j;
         itr2 = k;
         rotate(itr1,j,last);
         while (last != j)
         {
            ++j;
            ++itr2;
         }
         rotate(k,itr2,last);
         return true;
      }
   }
   rotate(first,k,last);
   return false;
}

inline double get_time_sec(void){
    return static_cast<double>(chrono::duration_cast<chrono::nanoseconds>(chrono::steady_clock::now().time_since_epoch()).count())/1000000000;
}

template<typename T>
T gcd(T a, T b) {
    if(a > b) swap(a, b);
    if(a == 0) return b;
    else return gcd(b%a, a);
}

template<typename T>
T lcm(T a, T b) {
    return (a / gcd(a, b)) * b;
}

template<typename T>
map<T, T> prime_list(T n) {
    map<T, T> ret;
    for(T i = 2; i*i <= n; i++) {
        if(n % i == 0) {
            ret[i] = 0;
            while(n % i == 0) {
                n /= i;
                ret[i]++;
            }
        }
    }
    if(n != 1) ret[n]++;
    return ret;
}

#define MOD 1000000007

LL mypow(LL a, LL n) {
    if(n == 0) return 1;
    if(n == 1) return a % MOD;
    if(n % 2 == 1) return (a * mypow(a, n-1)) % MOD;
    LL t = mypow(a, n/2);
    return (t * t) % MOD; 
}

LL mycomb(LL n, LL k) {
    if(n == 0 || n == k) return 1;
    LL x = 1, y = 1;
    REP(i, k) {
        x = x * (n-i) % MOD;
        y = y * (i+1) % MOD;
    }
    return x * mypow(y, MOD - 2) % MOD;
}

VLL par, rnk, sz;

int root(int x) {
    if(par[x] == x) return x;
    else return par[x] = root(par[x]);
}

bool same(int x, int y) {
    x = root(x);
    y = root(y);
    return x == y;
}

void unite(int x, int y) {
    x = root(x);
    y = root(y);
    if(rnk[x] < rnk[y]) {
        par[x] = y;
        sz[y] += sz[x];
    } else {
        par[y] = x;
        sz[x] += sz[y];
        if(rnk[x] == rnk[y]) rnk[x]++;
    }
}

#define INF 1e15

typedef tuple<LL, LL, LL, LL> T;

int main(void) {
    LL x, y, z, k;
    cin >> x >> y >> z >> k;
    VLL  a(x), b(y), c(z);
    REP(i, x) cin >> a[i];
    REP(i, y) cin >> b[i];
    REP(i, z) cin >> c[i];
    sort(ALL(a), greater<LL>());
    sort(ALL(b), greater<LL>());
    sort(ALL(c), greater<LL>());
    priority_queue<T, vector<T>> q;
    q.push(make_tuple(a[0] + b[0] + c[0], 0, 0, 0));
    map<T, bool> m;
    REP(i, k) {
        auto t = q.top();
        q.pop();
        cout << get<0>(t) << endl;
        LL d, e, f;
        d = get<1>(t);
        e = get<2>(t);
        f = get<3>(t);
        if(d+1 < x && !m[make_tuple(a[d+1] + b[e] + c[f], d+1, e, f)]) {
            q.push(make_tuple(a[d+1] + b[e] + c[f], d+1, e, f));
            m[make_tuple(a[d+1] + b[e] + c[f], d+1, e, f)] = true;
        }
        if(e+1 < y && !m[make_tuple(a[d] + b[e+1] + c[f], d, e+1, f)]) {
            q.push(make_tuple(a[d] + b[e+1] + c[f], d, e+1, f));
            m[make_tuple(a[d] + b[e+1] + c[f], d, e+1, f)] = true;
        }
        if(f+1 < z && !m[make_tuple(a[d] + b[e] + c[f+1], d, e, f+1)]) {
            q.push(make_tuple(a[d] + b[e] + c[f+1], d, e, f+1));
            m[make_tuple(a[d] + b[e] + c[f+1], d, e, f+1)] = true;
        }
    }
}