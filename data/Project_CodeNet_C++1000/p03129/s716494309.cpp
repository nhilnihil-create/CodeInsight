#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  

    int n, k;
    cin >> n >> k;
    int odd = n/2 + (n&1);
    cout << (odd >= k ? "YES" : "NO" );
}
