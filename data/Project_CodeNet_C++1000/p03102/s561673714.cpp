#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, M, C;
    cin >> N >> M >> C;
    vector<int> B(M);
    for(int i = 0; i < M; i++) cin >> B[i];
    vector<vector<int>> A(N, vector<int>(M));
    int cnt = 0;
    for(int i = 0; i < N; i++){
        int temp = C;
        for(int j = 0; j < M; j++) {
            cin >> A[i][j];
            temp += A[i][j] * B[j];
        }
        if(temp > 0) cnt++;
    }
    cout << cnt << endl;
}