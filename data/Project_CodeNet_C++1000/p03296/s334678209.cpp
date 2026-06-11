#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N;
    cin >> N;
    int ans = 0;
    vector<int>a(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        if(i) {
            if(a[i] == a[i-1]) {
                ans++;
                a[i] = 10000+i;
            }
        }
    }
    cout << ans << endl;
}
