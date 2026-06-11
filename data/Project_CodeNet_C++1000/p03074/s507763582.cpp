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
    ll n, k, ans=0, now=0;
    string s;
    cin >> n >> k >> s;
    
    vector<ll> num;
    if(s[0] == '0') num.push_back(0);
    ll tmp = 1;
    frep(i, 1, n-1) {
        if(s[i-1] == s[i]) {
            tmp++;
        }
        else {
            num.push_back(tmp);
            tmp = 1;
        }
    }
    num.push_back(tmp);
    if(s[n-1] == '0') num.push_back(0);

    if((num.size()-1)/2 <= k) ans = n;
    else {
        rep(i, 2*k+1) {
            now += num[i];
        }
        ans = now;
        rep(i, (num.size()-1)/2-k) {
            now -= (num[2*i]+num[2*i+1]);
            now += (num[2*(k+i)+1]+num[2*(k+i)+2]);
            if(ans < now) ans = now;
        }
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
        ret %= MOD;
        count *= 2;
    }
    if(count == n) return ret;
    else return (ret * a_n(a, n-count))%MOD;
}

ll my_gcd(ll a, ll b) {
    if(b == 0) return a;
    return my_gcd(b, a%b);
}

ll inv(ll a) {
    return a_n(a, MOD-2);
}

