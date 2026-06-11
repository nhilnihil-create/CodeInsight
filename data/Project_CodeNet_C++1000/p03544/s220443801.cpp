#include <bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
    #include "/home/v-o_o-v/deb.h"
    #define deb(x...)cerr << "[" << #x << "] = [";_print(x);
#else
    #define deb(x...)
#endif

#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    int n;
    cin >> n;
    ll f[n + 1];
    f[0] = 2LL;f[1] = 1LL;
    for(int i = 2; i <= n; i++)f[i] = f[i - 1] + f[i - 2];
    cout << f[n] << '\n'; 
    return 0;
}
// Write Here
