#include <bits/stdc++.h>

using namespace std;

using ll = long long;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e18;

int main() {
    ll n, m, i, j, k;
    cin >> n;
    map<ll,ll> d;
    while(n--){
        cin >> i;
        d[i]++;
    }
    cin >> m;
    while(m--){
        cin >> i;
        if(d[i]==0){
            cout << "NO" << endl;
            return 0;
        }
        d[i]--;
    }
    cout << "YES" << endl;
    return 0;
}