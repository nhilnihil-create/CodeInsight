#include <bits/stdc++.h>
#include <set>
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)

#define INF 100000000
#define MOD 100000007

#define writeln(n) cout<<n<<endl

using namespace std;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;
//vector<tuple<long long, long long, long long>>vec;

template<class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

llong pownew(llong m, llong n) {
    if (n == 0) { return 1; }
    if (n % 2 == 0) { return pow(m*m, n/2); }
    return pow(m, n-1) * m;
}

bool isprime(int p) {
    if (p == 1) return false;
    for (int i = 2; i < p; i++) {
        if (p%i == 0) return false;
    }
    return true;
}

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

const int inf=100000000;

long long modpow(long long a, long long n, long long mod) //a^n
{
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

llong gcd(llong a, llong b) {
    return b != 0 ? gcd(b, a % b) : a;
}
//setprecision(10);



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,a,b;
    cin>>n>>a>>b;
    int m=a+b-n;
    if(m<0) m=0;
    cout<<min(a,b)<<" "<<m<<endl;

    return  0;
}
