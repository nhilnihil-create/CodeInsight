#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N,a,ru,ld;
    int lastsum = 0;
    int maxsum = 0;
    cin >> N;
    vector<vector<int>> A(2,vector<int>(N));
    vector<vector<int>> sum(2,vector<int>(N));
    for(int i=0;i<2;i++) {
        for(int j=0;j<N;j++) {
            cin >> A[i][j];
        }
    }

    for(int i=0;i<N;i++) {
        sum[0][i] = lastsum + A[0][i];
        lastsum = sum[0][i];
    }

    lastsum = 0;
    for(int i=N-1;i>=0;i--) {
        sum[1][i] = lastsum + A[1][i];
        lastsum = sum[1][i];
    }

    for(int i=0;i<N;i++) {
        lastsum = sum[0][i] + sum[1][i];
        if(maxsum < lastsum) {
            maxsum = lastsum;
        }
    }

    cout << maxsum << endl;
    return 0;
}
