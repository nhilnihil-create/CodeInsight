#include<iostream>
using namespace std;

long long N, x[200000], X, x_sum[200001] = {};
// x_sum[t] := sum of x in [0, t)

long long E(long long i, long long x){
    if(i == 1){
        return 5 * x;
    }else{
        return (2 * i + 1) * x;
    }
}

int main(){
    cin >> N >> X;
    for(int i = 0; i < N; i++){
        cin >> x[i];
        x_sum[i+1] = x_sum[i] + x[i];
    }
    unsigned long long ans = 4e18;
    for(int k = 1; k <= N; k++){
        unsigned long long ans_k = 0;
        ans_k += N * X + k * X;

        for(int j = 1; j <= (N+k-1)/k; j++){
            int first_idx = N - k * (j - 1);
            int second_idx = max(0LL, N - k * j);
            ans_k += E(j, x_sum[first_idx] - x_sum[second_idx]);
        }
        /*
        for(int i = 1; i <= N; i++){
            ans_k += E((i+k-1)/k, x[N-i]);
            // i = 1, 2, ..., k
            // x[N-1], ..., x[N-k]
            // [N-k, N) = [0, N) \ [0, N-k)
        }
        */
        ans = min (ans, ans_k);
    }
    cout << ans << endl;
}
