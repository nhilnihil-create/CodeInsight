#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e10;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int M,K;
    cin >> M >> K;
    if(K > pow(2,M)-1) {
        cout << -1 << endl;
        return 0;
    }
    if(M == 1) {
        if(K == 0) cout << "0 0 1 1" << endl;
        else cout << -1 << endl;
        return 0;
    }
    if(M == 0) {
        cout << "0 0" << endl;
        return 0;
    }
    for(int i = 0; i < pow(2,M); i++) {
        if(i == K) {
            continue;
        }
        cout << i << " ";
    }
    cout << K << " ";
    for(int i = pow(2,M)-1; i >= 0; i--) {
        if(i == K) {
            continue;
        }
        cout << i << " ";
    }
    cout << K << endl;
}
