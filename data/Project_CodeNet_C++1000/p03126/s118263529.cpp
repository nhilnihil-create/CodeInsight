#include <iostream>
#include <vector>
#include <cmath>
typedef unsigned long long ll;
using namespace std;

int main(void) {
    int N, M; cin >> N >> M;
    int C[M];
    for(int l = 0; l < M; l++) C[l] = 0;
    
    for(int i = 0; i < N; i++){
        int K; cin >> K;
        for (int j = 0; j < K; j++) {
            int y; cin >> y;
            C[y - 1]++;
        }
    }
    int ans = 0;
    for(int l = 0; l < M; l++){
        if (C[l] == N )
            ans += 1;
    }
    cout << ans << endl;
    return 0;
}