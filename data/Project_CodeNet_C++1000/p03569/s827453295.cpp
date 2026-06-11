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
    string s,t;
    cin >> s;
    rep0(i, s.size()){
        if(s[i] != 'x')t += s[i];
    }
    rep0(i, t.size() / 2){
        if(t[i] != t[t.size() - i - 1]){
            pf(-1);
            return 0;
        }
    }
    ll l = 0,r = s.size() - 1,ans = 0;
    while (l < r) {
        if(s[l] != s[r]){
            ++ans;
            if(s[l] == 'x')++l;
            else if(s[r] == 'x')--r;
        }else{
            ++l;
            --r;
        }
    }
    pf(ans);
    return 0;
}
