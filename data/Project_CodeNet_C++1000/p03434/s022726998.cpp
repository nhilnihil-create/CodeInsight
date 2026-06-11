#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e16+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N;
    cin >> N;
    vector<int>a(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    sort(a.rbegin(),a.rend());
    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(i%2 == 0) {
            ans += a[i];
        }
        else {
            ans -= a[i];
        }
    }
    cout << ans << endl;
}
