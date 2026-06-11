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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, c;
    cin >> n >> m >> c;
    int b[m];
    for(int i = 0; i < m; i++)cin >> b[i];
    int ans = 0;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = 0; j < m; j++){
            int x;
            cin >> x;
            sum += (x * b[j]);
        }
        // deb(sum);
        if(sum + c > 0)ans++;
    }
    cout << ans << '\n';
    return 0;
}
// Write Here
