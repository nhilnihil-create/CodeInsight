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

int main(){
    ll n;
    cin >> n;

    vector<ll> a(n, 0);

    ll currGcd;
    REP(i, n){
        cin >> a[i];
        if (i == 0) currGcd = a[i];
        else currGcd = gcd(currGcd, a[i]);
    }
    cout << currGcd << endl;
}
        

 