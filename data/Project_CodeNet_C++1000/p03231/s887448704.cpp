#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
typedef long long ll;
#define pb push_back

ll gcd(ll a, ll b){
    if(a < 0) a = -a;
    if(b < 0) b = -b;
    if(b == 0) return a;
    else return gcd(b, a%b);
}

ll lcm(ll a, ll b){
    ll g = gcd(a, b);
    return a/g * b;
}

void solve(){
    ll n, m; cin >> n >> m;
    string s, t;
    cin >> s;
    cin >> t;

    if(s[0] != t[0]) cout << -1 << endl;
    else{
        ll l = lcm(n, m);
        ll g = gcd(n, m);
        ll i = 0;
        bool flag = true;
        while(i*n/g < n && i*m/g < m){
            if(s[i*n/g] != t[i*m/g]) flag = false;
            i++;
        }
        if(flag) cout << l << endl;
        else cout << -1 << endl;
    }

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}