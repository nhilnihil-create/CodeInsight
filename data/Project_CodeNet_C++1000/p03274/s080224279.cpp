#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
#define rep(i, n) for(int i=0; i<n; ++i)
#define REP(i, n) for(int i=1; i<=n; ++i)
#define all(obj) (obj).begin(), (obj).end()
using P = pair<int, int>;
const int inf = 100100100;
const ll INF = 1e18;
const ll MOD = 1e9+7;

int main(){
    int n, k; cin >> n >> k;
    vector<int> v(n);
    rep(i, n) cin >> v[i];
    int ans = inf;
    if(n == k){
        ans = min(abs(v[n-1]) + abs(v[0] - v[n-1]), abs(v[0]) + abs(v[0] - v[n-1]));
    }
    rep(i, n-k+1){
        ans = min(ans, min(abs(v[i+k-1]) + abs(v[i] - v[i+k-1]), abs(v[i]) + abs(v[i] - v[i+k-1])));
    }
    cout << ans << endl;
    return 0;
}