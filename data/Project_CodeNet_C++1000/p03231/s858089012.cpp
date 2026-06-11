#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e10
#define ALL(v) v.begin(), v.end()

using namespace std;
typedef unsigned long long ll;

ll gcd(ll a, ll b){
    if (a < b) swap(a,b);
    if (a % b == 0) return b;
    return gcd(a % b, b);
}
ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}

int main(){
    ll n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;

    ll lcm2 = lcm(n, m);
    ll gcd2 = gcd(n, m);

    ll n2 = n/gcd2;
    ll m2 = m/gcd2;

    REP(k, gcd2){
        if (s[k*n2] != t[k*m2]){
            cout << "-1" << endl;
            return 0;
        }
    }

    cout << lcm2 << endl;
    return 0;
    
}
        
