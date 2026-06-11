#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int N,M,C; cin >> N >> M >> C;
    vector<int> B(M);
    for(int i = 0; i < M; i++){
        cin >> B[i];
    }

    int ans = 0;
    vector<vector<int>> A(N, vector<int>(M));
    for(int i = 0; i < N; i++){
        int sum = 0;
        for(int j = 0; j < M; j++){
            cin >> A[i][j];
            sum += B[j]*A[i][j];
        }
        if(sum + C > 0){
            ans += 1;
        }
    }

    cout << ans << endl;

}
