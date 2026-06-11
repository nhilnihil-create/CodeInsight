#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;


int main(){
    int N; cin >> N;
    vector<int> a(N), b(N), c(N);
    rep(i, N) cin >> a[i];
    rep(i, N) cin >> b[i];
    rep(i, N) cin >> c[i];
    sort(all(a));
    sort(all(b));
    sort(all(c));
    vector<ll> sum(N + 1);
    sum[0] = 0;
    for(int i = 0; i < N; i++){
        auto itr = upper_bound(all(c), b[i]);
        sum[i + 1] = sum[i] + N - (itr - c.begin());
    }
    //下準備終わり
    ll ans = 0;
    rep(i, N){
        auto itr = upper_bound(all(b), a[i]);
        ans += sum[N] - sum[itr - b.begin()];
    }
    // rep(i, N + 1)cout << sum[i] << endl;
    cout << ans << endl;
}