#include<bits/stdc++.h>
// #define int long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
#define MOD 1000000007
using namespace std;
using ll = long long;
typedef vector<int> vi;

signed main() {
    int all = 1, n;
    cin >> n;
    vi a(n+1);
    int he = 1;
    rep(i, n){
        cin >> a[n];
        if(a[n] % 2 == 0) he*=2;
        all *= 3;
    }


    ll ans = all - he;
    cout << ans << endl;


}