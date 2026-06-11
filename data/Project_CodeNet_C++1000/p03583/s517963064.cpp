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
    for(int i = 1; i <= 3500; i++) {
        for(int j = 1; j <= 3500; j++) {
            int X = 4*i*j;
            // X*w == N*(i*j+i*w+j*w)
            // X*w == N*i*j+(N*i+N*j)*w
            // X*w == N*i*j+(N*(i+j))*w:
            //N*i*j = X*w-(N*(i+j))*w
            //N*i*j = (X-(N*(i+j)))*w:
            int Y = N*i*j;
            if(X <= N*(i+j)) {
                continue;
            }
            if(Y%(X-(N*(i+j))) == 0) {
                cout << i << " " << j << " " << Y/(X-(N*(i+j))) << endl;
                return 0;
            }
        }
    }
}