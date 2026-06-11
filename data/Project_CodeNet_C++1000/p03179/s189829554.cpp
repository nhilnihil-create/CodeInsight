#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
 
#define pii pair<ll, ll>
#define F first
#define S second
#define pb push_back
#define mp make_pair
 
const int N = 3e6 + 5;
const int mod = 1e9+7;
const ll INF = (ll)4e18 + 5;

inline int mul(int a, int b){
    return ((ll)a * b) % mod;
}

// inline int add(int a, int b){
//     int ans = a + b;
//     if(ans >= mod) ans -= mod;
//     return ans; 
// }

bool isprime(ll n){
    if(n<2) return false;
    for(ll i=2;i*i*i<=n;++i) if(n%i==0) return false;
    for(int it=0;it<1e2;++it){
        ll i = rand()%(n-1)+1;
        if(__gcd(i,n)!=1) return false;
        // if(mpow(i,n-1,n)!=1) return false;
    }
    return true;
}

ll fast_pow(ll a, ll b){
    ll ans = 1;
    a %= mod;
    while(b){
        if(b&1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return ans;
}

struct Matrix{
    vector<vector<ll>> m;
    int r, c;

    Matrix(int x){
        r = c = x;
        m.resize(x, vector<ll>(x, 0));
        // for(int j = 0; j < x; j++) m[j][j] = 1;
    }

    Matrix mult(Matrix& l, Matrix& r){
        Matrix ans(l.r);
        for(int j = 0; j < l.r; j++)
            for(int i = 0; i < r.c; i ++){
                ll &cur = ans.m[j][i];
                cur = 0;
                for(int k  = 0; k < l.c; k ++)
                    cur = (cur + (l.m[j][k] * r.m[k][i]) % mod) % mod;
            }
        return ans;
    }
};

// Matrix fast_mat_pow(Matrix& a, ll b){
//     Matrix ans;
//     while(b){
//         if(b&1) ans = ans.mult(ans, a);
//         a = a.mult(a, a);
//         b /= 2;
//     }
//     return ans;
// }

struct seg_tree{
    vector<int> seg;
    int n;

    seg_tree(int x) : n(x) {
        seg.resize(4*n);
    }

    void update(int ind, int val, int l = 0, int r = -1, int i = 0){
        if (r == -1) r += n;
        if (l == r) {
            seg[i] = val;
            return;
        }
        int m = (l+r) >> 1;
        if (m >= ind) update(ind, val, l, m, i*2+1);
        else update(ind, val, m+1, r, i*2+2);
        seg[i] = seg[i*2+1] + seg[i*2+2];
    }

    int query (int x, int y, int l = 0, int r = -1, int i = 0) {
        if (r == -1) r += n;
        if (r < x || l > y) return 0;
        if (l >= x && r <= y) return seg[i];
        int m = (l+r) >> 1;
        return (query(x, y, l, m, i*2+1) + query(x, y, m+1, r, i*2+2));
    }
};

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    // srand(unsigned(time(0)));
    // vector<int> prime;
    // vector<int> seive(N, 0);
    // seive[0] = seive[1] = 1;
    // for(int j = 4; j < N; j+=2) seive[j] = 2;
    // for(int j = 3; j*j < N; j += 2) if(!seive[j])
    //     for(int k = j*j; k < N; k += j+j) if(!seive[k]) seive[k] = j;

    // for(int j = 2; j < N; j++)
    //     if(seive[j] == 0) prime.pb(j);

    // cout << prime.size() << endl;
    // for(int j = 0; j < 10; j ++) cout << prime[j] << " "; cout << endl;

    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> dp(n+1, 0);
    dp[1] = 1;
    for (int j = 0; j < n-1; j ++) {
        for (int i = 1; i <= n; i ++) {
            dp[i] = (dp[i-1] + dp[i]) % mod;
        }
        vector<int> new_dp(n+1);
        for (int cur = 1; cur <= j+2; cur ++) {
            // fill the current position with 'j'
            if (s[j] == '<') {
                new_dp[cur] = (new_dp[cur] + dp[cur-1]) % mod;
            }
            else {
                new_dp[cur] = (new_dp[cur] + (dp[n] - dp[cur-1] + mod) % mod) % mod;
            }
        }
        dp = new_dp;
    }
    int ans = 0;
    for (auto i : dp) ans = (ans + i) % mod;
    cout << ans << endl;
    return 0;
}