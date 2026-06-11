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

int main() {
    vector<ll> num = {2,5,5,4,5,6,3,7,6};
    vector<P> match; // (数字、本数)
    ll n, m;
    cin >> n >> m;
    vector<ll> dp(n+1, -1*INF);
    rep(i, m) {
        ll a;
        cin >> a;
        a--;
        match.push_back(make_pair(a+1,num[a]));
    }
    sort(ALL(match), greater<P>());

    dp[0] = 0;
    frep(i, 1, n) {
        ll max = -1*INF;
        rep(j, m) {
            if(i-match[j].second >= 0) {
                if(max < dp[i-match[j].second]+1) {
                    max = dp[i-match[j].second]+1;
                }
            }
        }
        dp[i] = max;
    }

    ll tmp = n;
    rep(i, dp[n]) {
        rep(j, m) {
            if(dp[tmp-match[j].second] == dp[tmp]-1) {
                cout << match[j].first;
                tmp -= match[j].second;
                break;
            }
        }
    }

    cout << endl;
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

