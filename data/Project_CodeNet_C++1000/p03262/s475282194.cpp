#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e9
#define ALL(v) v.begin(), v.end()

using namespace std;
typedef long long ll;


ll gcd(ll a, ll b){
    if(a==0) return b;
    if (a < b) swap(a,b);
    if (a % b == 0) return b;
    return gcd(a % b, b);
}
ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}
ll countNonDivisor(ll x, ll c, ll d){
    return x - x/c -x/d + x/lcm(c, d);
}
int main(){
    ll n, x;
    cin >> n >> x;
    vector<ll>a(n, 0);
    REP(i, n) cin >> a[i];

    // vector<ll>dist(n-1, 0);
    sort(ALL(a));

    ll initDist = INF;
    REP(i, n){
        if (abs(a[i] - x) < initDist) initDist = abs(a[i]-x);
    }
    ll currGcd = initDist;

    ll dist = 0;

    REP(i, n-1){
        dist = a[i+1] - a[i];
        currGcd = gcd(currGcd, dist);
    }

    cout << currGcd << endl;
}
