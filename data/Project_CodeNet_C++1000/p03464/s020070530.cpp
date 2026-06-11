#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 1e5 + 7;
int n, a[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    reverse(a, a + n);
    int l = 2, r = 2;
    for (int i = 0; i < n; ++i) {
        l = ((l + a[i] - 1) / a[i]) * a[i];
        r = (r / a[i]) * a[i] + a[i] - 1;            
        if (r < l) {
            cout << "-1\n";
            exit(0);
        }   
    }   
    cout << l << ' ' << r << '\n';
}   