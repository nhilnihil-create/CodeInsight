#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N;
    cin >> N;
    for(int i = 1; i <= 3500; i++) {
        for(int j = 1; j <= 3500; j++) {
            int X = 4*i*j-N*i-N*j;
            if(X <= 0) {
                continue;
            }
            if(i*j*N%X == 0) {
                cout << i << " " << j << " " << (i*j*N)/X << endl;
                return 0;
            }
        }
    }
}
