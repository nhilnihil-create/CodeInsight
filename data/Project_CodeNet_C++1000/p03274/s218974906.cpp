#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;

int main(){
    int N, K; cin >> N >> K;
    vector<ll> a(N);
    rep(i, N) cin >> a[i];
    ll ans = INF;
    rep(i, N){
        if(i + K - 1 >= N)continue;
        ll tmp = abs(0 - a[i]) + abs(a[i] - a[i + K - 1]);
        ans = min(ans, tmp);
        tmp = abs(0 - a[i + K - 1]) + abs(a[i + K - 1] - a[i]);
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}
