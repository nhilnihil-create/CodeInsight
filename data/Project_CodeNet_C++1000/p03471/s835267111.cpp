#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e16+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N,Y;
    cin >> N >> Y;
    Y/=1000;
    for(int i = 0; i <= N; i++) {
        for(int j = 0; i+j <= N; j++) {
            int k = N-i-j;
            if(i*10+j*5+k == Y) {
                cout << i << " " << j << " " << k << endl;
                return 0;
            }
        }
    }
    cout << -1 << " " << -1 << " " << -1 << endl;
}
