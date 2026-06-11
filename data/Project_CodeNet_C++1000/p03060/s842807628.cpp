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
    
    int n;
    cin >> n;
    int v[n], c[n];
    int ans = INT_MIN;
    for(int i = 0; i < n; i++)
        cin >> v[i];
    for(int i = 0; i < n; i++)
        cin >> c[i];

    for(int i = 0; i < (1 << n); i++){
        int cost = 0, sum = 0;
        for(int j = 0; j < n; j++){
            if(i & (1 << j)){
                cost += c[j];
                sum += v[j];
            }
        }
        ans = max(ans, sum - cost);
    }
    cout << ans << '\n';
    return 0;
}
// Write Here
