#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9 + 7;
const ll LINF = 1LL << 62;
const int INF = 1e9 + 7;

vector<vector<ll>> g(100010); 
vector<ll> dist(100010);

int main(){
    ll n, z, w;
    cin >> n >> z >> w;

    ll a[n];
    rep(i, n)cin >> a[i];

    if(n == 1)cout << abs(w - a[0]);
    else cout << max(abs(w-a[n-1]), abs(a[n-2] - a[n-1]));
}