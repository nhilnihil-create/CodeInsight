#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1234567;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N;
    cin >> N;
    vector<int>h(N);
    for(int i = 0; i < N; i++) {
        cin >> h[i];
    }
    int ans = 0;
    for(int i = 1; i < N; i++) {
        if(h[i-1] <= h[i]) {
            continue;
        }
        ans+=h[i-1]-h[i];
    }
    cout << ans+h[N-1] << endl;
}
