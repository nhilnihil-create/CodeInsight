#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const long long INF = 1LL << 60;
const ll C = 1000000000+7;

int main() {
    int N, K;
    cin >> N >> K;
    vector<ll> num(K, 0);
    for(int i=1; i<=N; i++) num[i%K]++;
    ll res = 0;
    for(int a = 0; a < K; a++) {
        int b = (K-a)%K;
        int c = (K-a)%K;
        if((b+c) % K != 0) continue;
        res += num[a] * num[b] * num[c];
    }
    cout << res << endl;
}