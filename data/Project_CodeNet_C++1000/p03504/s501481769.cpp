#include <bits/stdc++.h>
using namespace std;
#define rep0(i,n) for(ll (i) = 0; (i) < (n); ++(i))
#define rrep0(i,n) for(ll (i) = (n) - 1; (i) >= 0; --(i))
#define rep1(i,n) for(ll (i) = 1; (i) <= (n); ++(i))
#define rrep1(i,n) for(ll (i) = (n); (i) >= 1; --(i))
#define nfor(i,a,b) for(ll (i) = (a); (i) < (b); ++(i))
#define rnfor(i,a,b) for(ll (i) = (a) - 1; (i) >= (b); --(i))
#define ll long long
#define mod (1000000007)
#define pf(x) cout << (x) << endl
#define all(x) (x).begin(),(x).end()

ll gcd(ll a,ll b){
    if(a < b)swap(a, b);
    if(b == 0) return a;
    return gcd(b,a%b);
}

ll lcm(ll a,ll b){
    ll g = gcd(a,b);
    return a / g * b;
}

ll factorial(ll n){
    ll t = 1;
    rep1(i, n)t *= i;
    return t;
}

ll combinations(ll n, ll k) {
    ll r = 1;
    rep1(i, k)r = r * n-- / i;
    return r;
}

int main(){
    ll n,c;
    cin >> n >> c;
    vector<vector<int>> cnt(1e5 + 1,vector<int>(c + 1,0));
    rep0(i, n){
        ll s,t,c;
        cin >> s >> t >> c;
        ++cnt[s - 1][c];
        --cnt[t][c];
    }
    rep1(i, c){
        rep1(j, 1e5){
            cnt[j][i] += cnt[j - 1][i];
        }
    }
    int ans = 0;
    rep1(i, 1e5){
        int t = 0;
        rep1(j, c){
            if(cnt[i][j] >= 1)++t;
        }
        ans = max(ans,t);
    }
    pf(ans);
    return 0;
}
