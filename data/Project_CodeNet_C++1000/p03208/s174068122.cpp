#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL << 60;

int main(){
    ll N, K;
    cin >> N >> K;
    vector<ll> h(N);
    for (int i = 0; i < N; i++) cin >> h[i];

    sort(h.begin(), h.end(), greater<ll>());
    ll out = INF;
    for (int i = 0; i <= N - K; i++) out = min(out, h[i] - h[i + K - 1]);
    cout << out << endl;

    return 0;
}