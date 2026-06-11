#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<vector<int>> A(2, vector<int> (N));
    for(int i = 0; i < 2; i++){
        for(int j = 0;j < N; j++) cin >> A[i][j];
    }
    int ans =0;
    int temp = 0;
    for(int i = 0; i < N; i++){
        temp += A[0][i];
        int res = temp;
        for(int j = i; j < N; j++){
            res += A[1][j];
        }
        ans = max(ans, res);
    }
    cout << ans << endl;
}