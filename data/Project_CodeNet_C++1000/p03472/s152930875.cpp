#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 2e9;
//const ll INF = 9e18;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, H;
    cin >> N >> H;
    vector<int> a(N),b(N);
    for (int i=0;i<N;i++) cin >> a[i] >> b[i];
    sort(a.rbegin(),a.rend());
    sort(b.rbegin(),b.rend());
    int ans = INF;
    for (int i=0;i<=N;i++){
        if (i > 0) H-=b[i-1];
        int cnt = 0;
        if (H > 0) cnt = (H+a[0]-1)/a[0];
        ans = min(ans, i+cnt);
    }
    cout << ans << "\n";
}