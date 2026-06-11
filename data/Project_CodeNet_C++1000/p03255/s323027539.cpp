#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int N;
    int64_t X, x[200001];
    cin >> N >> X;
    for(int i=1; i<=N; i++) cin >> x[i];
    int64_t accum[200001] = {0};
    for(int i=1; i<=N; i++) accum[i] = x[i] + accum[i-1];
 
    int64_t ans = 2e15;
    for(int k=1; k<=N; k++){
        int64_t result = (N+k) * X;
        for(int j=0; j<(N-1)/k+1; j++){
            int M = N - j*k;
            int m = max(0, M-k);
            int c = j==0 ? 5 : 2*j+3;
            result += c * (accum[M] - accum[m]);
            if(result >= ans) break;
        }
        ans = min(ans, result);
    }
    cout << ans << endl;
    return 0;
}