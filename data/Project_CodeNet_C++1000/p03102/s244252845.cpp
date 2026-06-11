#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, C;
    cin >> N >> M >> C;
    vector<int> B(M);
    for(int i=0; i<M; i++) cin >> B[i];
    int A[M][N];
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> A[j][i];
        }
    }

    int count = 0;
    for(int i=0; i<N; i++) {
        int total = C;
        for(int j=0; j<M; j++) {
            total += (A[j][i] * B[j]);
        }
        if(total > 0) {
            count++;
        }
    }
    cout << count << endl;
}

