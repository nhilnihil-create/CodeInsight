#include<bits/stdc++.h>
/* #define int long long */
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
using ll = long long;
typedef vector<int> vi;


signed main() {
    int d;
    int n;
    cin >> d >> n;
    int ans;
    if(n == 100) n++;
    if(d == 0) cout << n << endl;
    else if(d == 1) cout << n * 100 << endl;
    else cout << n * 10000 << endl;

    // cout << cnt << endl;
}
