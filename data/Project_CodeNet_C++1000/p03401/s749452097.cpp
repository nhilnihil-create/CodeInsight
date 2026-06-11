#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <limits>
const int mod = 1e9 + 7;
#define INF 1000000000000000
typedef long long int ll;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
long long gcd(long long a, long long b) {
    if (a < b)
        swap(a, b);
    long long r = a % b;
    if (r == 0)
        return b;
    else
        return gcd(b, r);
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<ll> v(n+2);
    rep(i, n) cin >> v[i+1];
    v[0]=0;
    v[n+1]=0;
    int sum = 0;
    FOR(i,1,n+2) sum += abs(v[i]-v[i-1]);
    FOR(i,1,n+1){
        int ans = sum;
        ans -= abs(v[i]-v[i-1]);
        ans -= abs(v[i+1]-v[i]);
        ans += abs(v[i+1]-v[i-1]);
        cout<<ans<<endl;
    }
}