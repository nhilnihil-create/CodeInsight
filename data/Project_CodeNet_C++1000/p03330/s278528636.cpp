#include <bits/stdc++.h>
using namespace std;
int N, C;
long long D[31][31];
long long c[510][510];
long long cost[31][3] = {};

int main() {
    cin >> N >> C;
    for(int i=0; i<C; ++i) {
        for(int j=0; j<C; ++j) cin >> D[i][j];
    }
    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j) {
            cin >> c[i][j];
            --c[i][j];
        }
    }

    for(int k=0; k<C; ++k) {
        for(int i=0; i<N; ++i) {
            for(int j=0; j<N; ++j) {
                cost[k][(i + j) % 3] += D[c[i][j]][k];
            }
        }
    }

    long long res = 1001001001001001001;
    for(int i=0; i<C; ++i) {
        for(int j=0; j<C; ++j) {
            for(int k=0; k<C; ++k) {
                if(i == j || j == k || k == i) continue;
                res = min(res, cost[i][0] + cost[j][1] + cost[k][2]);
            }
        }
    }
    
    cout << res << '\n';
}