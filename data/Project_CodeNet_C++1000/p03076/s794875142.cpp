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
    
    int n = 5;
    vector<int> v = {0, 1, 2, 3, 4};
    vector<int> a(n);
    for(int i = 0; i < 5; i++)cin >> a[i];
    int ans = INT_MAX;
    do{ 
        int time = 0;
        vector<int> b = a;
        for(int i = 0; i < n - 1; i++){
            while(b[v[i]] % 10 != 0){
                b[v[i]]++;
            }
            time += b[v[i]];
        }
        ans = min(ans, b[v[4]] + time);
    }while(next_permutation(all(v)));
    cout << ans << '\n';
    return 0;
}
// Write Here
