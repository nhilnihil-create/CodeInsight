#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int D,N;
    cin >> D >> N;
    if(D == 0) {
        if(N == 100) {
            cout << 101 << endl;
        }
        else {
            cout << N << endl;
        }
    }
    if(D == 1) {
        if(N == 100) {
            cout << 10100 << endl;
        }
        else {
            cout << 100*N << endl;
        }
    }
    if(D == 2) {
        if(N == 100) {
            cout << 1010000 << endl;
        }
        else {
            cout << 10000*N << endl;
        }
    }
}
