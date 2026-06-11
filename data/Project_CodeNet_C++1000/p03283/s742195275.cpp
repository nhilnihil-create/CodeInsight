#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <queue>
#include <tuple>
#include <set>
#include <map>

using namespace std;

int main(void) {
    int N, M, Q;
    cin >> N >> M >> Q;
    vector< vector<int> > g(N+1, vector<int>(N+1));

    while(M--) {
        int L, R;
        cin >> L >> R;
        --L; --R;
        g[0][R]++;
        g[0][N]--;
        g[L+1][R]--;
        g[L+1][N]++;
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            g[i][j+1] += g[i][j];
        }
    }
    for(int j=0; j<N; j++) {
        for(int i=0; i<N; i++) {
            g[i+1][j] += g[i][j];
        }
    }

    while(Q--) {
        int p, q;
        cin >> p >> q;
        --p; --q;
        cout << g[p][q] << endl;
    }
    return 0;
}
