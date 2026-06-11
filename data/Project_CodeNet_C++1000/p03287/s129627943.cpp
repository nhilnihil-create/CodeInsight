#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    ll N, M;
    cin >> N >> M;
    vector<ll> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    vector<ll> sum(N+1);
    for (int i = 0; i < N; i++) sum[i+1] = sum[i] + a[i];

    map<ll, ll> mp;
    for (int i = 0; i < N+1; i++) mp[sum[i] % M]++;

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        mp[sum[i] % M]--;
        ans += mp[sum[i] % M];
    }
    cout << ans << '\n';
}
