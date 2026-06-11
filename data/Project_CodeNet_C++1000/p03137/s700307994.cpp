#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 1e5 + 3;

int main(){
    fast;
    ll n, m;
    cin >> n >> m;
    ll a[m];
    vii b;
    for(int i = 0; i < m; ++i) 
        cin >> a[i];
    if(n >= m){
        cout << "0\n";
        return 0;
    }
    sort(a, a + m);
    for(int i = 0; i < m - 1; ++i) 
        b.pb(abs(a[i] - a[i + 1]));
    sort(b.rbegin(), b.rend());
    ll ans = 0;
    for(int i = n - 1; i < m - 1; ++i) 
        ans += b[i];
    cout << ans;
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}