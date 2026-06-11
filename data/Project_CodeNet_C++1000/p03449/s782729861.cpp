#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    int A[2][N];
    int u[N], d[N];

    for(int i=0; i<2; i++){
        for(int j=0; j<N; j++){
            cin >> A[i][j];
        }
    }    

    u[0] = A[0][0];
    d[N-1] = A[1][N-1];

    for(int i=1; i<N; i++){
        u[i] = u[i-1] + A[0][i];
        d[N - i - 1] = d[N-i] + A[1][N - i - 1];
    }

    int ans = 0;
    for(int i=0; i<N; i++){
        int temp = u[i] + d[i];
        ans = max(ans, temp);
    }
    cout << ans << endl;
    return 0;
}