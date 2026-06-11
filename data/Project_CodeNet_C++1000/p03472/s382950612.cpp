#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 1LL << 60;
const ll mod = 1e9 + 7;

int main() {
    int N, H;
    cin >> N >> H;
    int maximum = 0;
    vector<int> v(N);
    for(int i = 0; i < N; i++) {
        int a;
        cin >> a >> v[i];
        maximum = max(maximum, a);
    }
    sort(v.begin(), v.end(), greater<int>());
    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(H <= 0 || maximum >= v[i]) break;
        H -= v[i];
        ans++;
    }
    if(H > 0) ans += (H + maximum - 1) / maximum;
    cout << ans << "\n";
    return 0;
}