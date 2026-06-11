#include <bits/stdc++.h>
using namespace std;


void solve(long long N, long long M){
    cout << pow(2, M) * (1900 * M + 100 * (N - M)) << endl;
    return;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    solve(N, M);
    return 0;
}
