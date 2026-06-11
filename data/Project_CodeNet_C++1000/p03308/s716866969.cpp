#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    ll ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            ans = max(ans, abs(a[i] - a[j]));
        }
    }
    cout << ans << endl;
    
    return 0;
}