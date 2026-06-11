#include <bits/stdc++.h>
#define int long long

using namespace std;

const int inf = (int)1e17;


void solve(){
    int n, c;
    cin >> n >> c;
    vector < int > x(n);
    vector < int > v(n);
    for(int i = 0; i < n; ++i){
        cin >> x[i] >> v[i];
    }
    int ans = 0;
    if(n == 1){
        ans = max(ans, v[0] - x[0]);
        ans = max(ans, v[0] - (c - x[0]));
        cout << ans << "\n";
        return;
    }
    vector < int > a(n);
    vector < int > ra(n);
    a[0] = -x[0] + v[0];
    for(int i = 1; i < n; ++i){
        a[i] = a[i - 1] - (x[i] - x[i - 1]) + v[i];
    }
    ra[0] = -(c - x[ra.size() - 1]) + v[ra.size() - 1];
    for(int i = 1; i < n; ++i){
        ra[i] = ra[i - 1] - (x[ra.size() - i] - x[ra.size() - 1 - i]) + v[ra.size() - 1 - i];
    }
    vector < int > pa(n);
    vector < int > pra(n);
    pa[0] = a[0];
    for(int i = 1; i < n; ++i){
        pa[i] = max(pa[i - 1], a[i]);
    }
    pra[0] = ra[0];
    for(int i = 1; i < n; ++i){
        pra[i] = max(pra[i - 1], ra[i]);
    }
//    cerr << "HERE\n";
//    for(int i = 0; i < a.size(); ++i){
//        cerr << a[i] << " ";
//    }
//    cerr << "\n";
//    for(int i = 0; i < ra.size(); ++i){
//        cerr << ra[i] << " ";
//    }
//    cerr << "\n";
//    for(int i = 0; i < n; ++i){
//        cerr << pa[i] << " ";
//    }
//    cerr << "\n";
//    for(int i = 0; i < pra.size(); ++i){
//        cerr << pra[i] << " ";
//    }
//    cerr << "\n";
//    cerr << "HERE\n";
    for(int i = 0; i < n; ++i){
        ans = max(ans, max(a[i], ra[i]));
        ans = max(ans, a[i] - x[i] + ((n - i - 2 >= 0) ? pra[n - i - 2] : -inf));
        //cerr << i << " " << a[i] << " " << x[i] << " " << ((n - i - 2 >= 0) ? pra[n - i - 2] : -inf) << "\n";
        ans = max(ans, ra[i] - (c - x[ra.size() - i - 1]) + ((n - i - 2 >= 0) ? pa[n - i - 2] : -inf));
    }
    cout << ans << "\n";

}



signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    #ifdef DEBUG
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        cin >> t;
    #endif
    for(int i = 0; i < t; ++i){
        solve();
    }
}
