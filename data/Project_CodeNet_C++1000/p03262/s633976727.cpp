#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

const ll mod = 1000000007;

int main() {
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> cities(n);
    rep(i, n) cin >> cities[i];
    cities.push_back(x);
    sort(cities.begin(), cities.end());
    if(n == 1){
        cout << cities[1] - cities[0] << endl;
        return 0;
    }
    
    ll ans;
    ans = __gcd(cities[1] - cities[0], cities[2] - cities[1]);
    for(int i = 3; i < n + 1; i++){
        ans = __gcd(ans, cities[i] - cities[i - 1]);
    }

    cout << ans << endl;
    
    return 0;
}
