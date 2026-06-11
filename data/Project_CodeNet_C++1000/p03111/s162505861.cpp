#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;


#define rep(i,n) for(ll (i)=0; (i)<(ll)(n); (i)++)
#define frep(i,m,n) for(ll (i)=(m); (i)<=(ll)(n); (i)++)
#define rrep(i,n) for(ll (i)=(n)-1; (i)>-1; (i)--)
#define frrep(i,m,n) for(ll (i)=(n); (i)>(ll)(m); (i)--)
#define ALL(x) (x).begin(), (x).end()

const ll INF = 100100100100100100;
const ll MOD = 1000000007;

// get abs
ll my_abs(ll a);
// a^n
ll a_n(ll a, ll n);
// get gcd
ll my_gcd(ll a, ll b);
// a^(-1) % MOD 
ll inv(ll a);

ll N, A, B, C;
vector<ll> l(8);

ll dfs(ll len, ll a, ll b, ll c) {
    if(len == N) {
        if(a == 0 || b == 0 || c == 0) {
            return 1000000007;
        }
        else {
            return my_abs(A-a) + my_abs(B-b) + my_abs(C-c) - 30;
        }
    }
    else {
        ll w,x,y,z;
        w = dfs(len+1, a, b, c);
        x = dfs(len+1, a+l[len], b, c) + 10;
        y = dfs(len+1, a, b+l[len], c) + 10;
        z = dfs(len+1, a, b, c+l[len]) + 10;
        return min({w,x,y,z});
    }
}

int main() {
    cin >> N >> A >> B >> C;
    rep(i, N) cin >> l[i];

    cout << dfs(0, 0, 0, 0) << endl;

    return 0;
}

ll my_abs(ll a) {
    if(a >= 0) return a;
    else return -1 *a;
}

ll a_n(ll a, ll n) { 
    if(n == 0) return 1;
    
    ll ret = a, count = 1;
    while(count * 2 < n) {
        ret *= ret;
        count *= 2;
    }
    if(count == n) return ret;
    else return (ret * a_n(a, n-count));
}

ll my_gcd(ll a, ll b) {
    if(b == 0) return a;
    return my_gcd(b, a%b);
}

ll inv(ll a) {
    return a_n(a, MOD-2);
}

