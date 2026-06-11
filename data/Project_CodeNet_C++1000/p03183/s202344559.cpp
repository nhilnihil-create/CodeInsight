#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

long long dp[1111][22222];

int main(){
    int N;
    cin >> N;
    vector<tuple<int, int, int, int>> A(N);
    for(int i=0; i<N; i++){
        int w, s, v;
        cin >> w >> s >> v;
        A[i] = make_tuple(w+s, w, s, v);
    }
    sort(A.begin(), A.end());

    for(int i=0; i<N; i++){
        int ws, w, s, v;
        tie(ws, w, s, v) = A[i];

        for(int j=0; j<22222; j++)
            dp[i+1][j] = dp[i][j];

        for(int j=0; j<=s; j++){
            if(j+w >= 22222) continue;
            dp[i+1][j+w] = max(dp[i+1][j+w], dp[i][j] + v);
        }
    }
    long long ans = 0;
    for(int i=0; i<22222; i++)
        ans = max(ans, dp[N][i]);
    cout << ans << endl;
    return 0;
}