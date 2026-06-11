#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    
    int N;
    cin >> N;
    int A[2][N];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < N; j++){
            cin >> A[i][j];
        }
    }
    
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int sum = A[0][0] + A[1][N-1];
        bool flag = false;
        for (int j = 1; j < N; j++) {
            if (j == N-i || flag) {
                sum += A[1][j-1];
                flag = true;
            }else{
                sum += A[0][j];
            }
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
}