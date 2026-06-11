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
// (a+b+c)%MOD
ll madd(ll a, ll b, ll c);
// (a-b)%MOD
ll msub(ll a, ll b);
// (a*b*c)%MOD
ll mtime(ll a, ll b, ll c);


int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> f(n+1, -1*INF);
    vector<P> sushi;
    rep(i, n) {
        ll t, d;
        cin >> t >> d;
        sushi.push_back(make_pair(d, t)); // 美味しさ先にする
    }
    sort(ALL(sushi), greater<P>());

    // 初期状態を作る
    // pqmaxは絶対解に必要, pqminは2番手以降なので抜いてもOK
    priority_queue<ll, vector<ll>, greater<ll>> pqmax, pqmin;
    ll sum = 0;
    set<ll> var; // どの寿司が含まれてるか
    rep(i, k) {
        sum += sushi[i].first;
        // 始めて来た寿司
        if(!var.count(sushi[i].second)) {
            var.insert(sushi[i].second);
            pqmax.push(sushi[i].first);
        }
        // 2番手以降の寿司
        else {
            pqmin.push(sushi[i].first);
        }
    }
    f[var.size()] = sum;

    frep(i, k, n-1) {
        // 始めて来た寿司に対してのみ操作をする
        if(!var.count(sushi[i].second) && pqmin.size() != 0) {
            // 最小値取り出し
            ll tp = pqmin.top();
            pqmin.pop();
            sum -= tp;
            // 新種を挿入
            sum += sushi[i].first;
            pqmax.push(sushi[i].first);
            var.insert(sushi[i].second);
            f[var.size()] = sum;
        }
    }

    ll ans = -1*INF;
    frep(i, 1, n) {
        if(f[i]+i*i > ans) ans = f[i]+i*i;
    }
    cout << ans << endl;

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

ll madd(ll a, ll b, ll c) {
    ll ret = (a+b) % MOD;
    return (ret+c) % MOD;
}

ll msub(ll a, ll b) {
    if(a < b) return (a-b+MOD) % MOD;
    else return (a-b) % MOD;
}

ll mtime(ll a, ll b, ll c) {
    ll ret = (a*b) % MOD;
    return (ret*c) % MOD;
}
