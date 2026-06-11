#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
//const int INF = 2e9;
//const ll INF = 9e18;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i=0;i<N;i++) cin >> A[i];
    vector<ll> sum(N+1);
    for (int i=0;i<N;i++) sum[i+1] = sum[i] + A[i];
    map<ll,ll> mp;
    ll ans = 0;
    mp[0]++;
    for (int i=1;i<=N;i++){
        ans += mp[sum[i]];
        mp[sum[i]]++;
    }
    cout << ans << "\n";
}