#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define ld long double
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define dbg(x) cerr << #x << ": " << x << '\n'
#define fast_io() ios::sync_with_stdio(false); cin.tie(0);
#define fi first
#define se second

signed main() {
    fast_io();
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    if(k & 1) cout << b - a; else cout << a - b;
    return 0;
}
