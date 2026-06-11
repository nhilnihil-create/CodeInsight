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
    ll n, k, sum=0;
    cin >> n >> k;
    //aの各桁の1の合計, i桁目を1,0にするとどれだけ合計が増えるか
    vector<ll> num(40, 0), one(40, 0), zero(40, 0), ans;
    rep(i, n) {
        ll a; cin >> a;
        ll bit = 0;
        while(a>0) {
            if((a%2) != 0) {
                num[bit]++;
            }
            a /= 2;
            bit++;
        }
    }
    rep(i, 40) {
        one[i] = a_n(2, i)*(n-num[i]);
        zero[i] = a_n(2, i)*num[i];
    }
    vector<ll> bi(40, 0);
    ll bit = 0;
    while(k>0) {
        if((k%2) != 0) {
            bi[bit]++;
        }
        k /= 2;
        bit++;
    }

    for(ll i = 39; i >= 0; i--) {
        // bi[i] == 1 の時x[i]を0としてその後の合計をチェック
        if(bi[i] == 0) {
            sum += zero[i];
        }
        else {
            ll tmp = 0;
            tmp += zero[i];
            for(ll j = i-1; j >= 0; j--) {
                tmp += max(zero[j], one[j]);
            }
            ans.push_back(sum+tmp);
            sum += one[i];
        }
    }
    ans.push_back(sum);
    sort(ALL(ans), greater<ll>());

    cout << ans[0] << endl;

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
