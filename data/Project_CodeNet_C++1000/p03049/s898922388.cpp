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
    ll n,ans = 0,cnta = 0,cntb = 0,cntab = 0;
    cin >> n;
    rep0(i, n){
        string s;
        cin >> s;
        if(s[0] == 'B' && s[s.size() - 1] == 'A')++cntab;
        else if(s[s.size() - 1] == 'A')++cnta;
        else if(s[0] == 'B')++cntb;
        rep0(j, s.size() - 1)if(s[j] == 'A' && s[j + 1] == 'B')++ans;
    }
    if(cntab){
        if(cnta && cntb){
            ans += cntab + 1;
            --cnta;
            --cntb;
        }else if(cnta || cntb){
            ans += cntab;
            if(cnta < cntb)--cntb;
            else --cnta;
        }else ans += cntab - 1;
    }
    ans += min(cnta,cntb);
    pf(ans);
    return 0;
}
