#include <bits/stdc++.h>
using namespace std;

const int MAX = 200010;
long long accum[MAX];
const long long INF = 1LL<<62;

int main(){
    long long i, j, k;
    long long N, X;
    cin >> N >> X;
    long long x[MAX];
    for(i=1; i<=N; i++) scanf("%lld", &x[i]);
    for(i=1; i<=N; i++) accum[i] = x[i] + accum[i-1];

    long long ans = INF;
    for(k=1; k<=N; k++){
        long long result = k*X;
        for(j=0; j<(N-1)/k+1; j++){
            int M = N - j*k;
            int m = max(0LL, M-k);
            long long c = j==0 ? 5 : 2*j+3;
            result += c * (accum[M] - accum[m]);
            if(result < 0) break;
        }
        if(result > 0) ans = min(ans, result);
    }
    cout << ans+N*X << endl;
    return 0;
}