#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e18;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int R,G,B,N;
    cin >> R >> G >> B >> N;
    int ans = 0;
    for(int i = 0; i*R <= N; i++) {
        for(int j = 0; i*R+j*G <= N; j++) {
            if((N-i*R-j*G)%B == 0) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}
