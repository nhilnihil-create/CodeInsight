#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

int main() {
    ll N, H, a;
    ll Max = 0;
    ll total = 0;
    ll ans = 0;
    cin >> N >> H;
    vector<ll>b(N);
    for (int i = 0; i < N; i++) {
        cin >> a >> b[i]; 
        Max = max(Max, a);
    }
    sort(b.begin(), b.end(), greater<ll>());

    for (int i = 0; i < N; i++) {
        if (b[i] > Max) {
            ans++;
            total += b[i];
        }
        if (total >= H) {
            break;
        }
    }

    if (total < H) {
        ans += ceil((double)(H-total)/(double)Max);
    }
    cout << ans << endl;
}
