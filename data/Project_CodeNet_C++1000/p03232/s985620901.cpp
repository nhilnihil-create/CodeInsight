#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cassert>
using namespace std;
#define MOD 1000000007

long long bipow(long long a, long long b){
    if(b == 0) return 1;
    if(b % 2) return (a * bipow(a, b-1)) % MOD;
    else{
        long long c = bipow(a, b/2);
        return (c * c) % MOD;
    }
}

int main(){
    long long N;
    cin >> N;
    vector<long long> A(N);
    for(int i=0; i<N; i++)
        cin >> A[i];

    vector<long long> B(N+1);
    for(int i=1; i<=N; i++)
        B[i] = bipow(i, MOD-2);

    vector<long long> C(N+1);
    for(int i=1; i<=N; i++)
        C[i] = (C[i-1] + B[i]) % MOD;

    vector<long long> D(N);
    for(int i=0; i<N; i++)
        D[i] = ((C[N-i] + C[i+1]) % MOD + MOD - 1) % MOD;

    long long ans = 0;
    for(int i=0; i<N; i++)
        ans = (ans + (D[i] * A[i]) % MOD) % MOD;

    for(int i=1; i<=N; i++)
        ans = (ans * i) % MOD;

    cout << ans << endl;
    return 0;
}
