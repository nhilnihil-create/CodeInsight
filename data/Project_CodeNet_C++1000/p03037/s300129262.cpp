#include <bits/stdc++.h>
using namespace std;


void solve(long long N, long long M, std::vector<long long> L, std::vector<long long> R){
    long long maxL = *max_element(L.begin(), L.end());
    long long minR = *min_element(R.begin(), R.end());
    cout << max(0LL, minR - maxL + 1) << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    std::vector<long long> L(M);
    std::vector<long long> R(M);
    for(int i = 0 ; i < M ; i++){
        scanf("%lld",&L[i]);
        scanf("%lld",&R[i]);
    }
    solve(N, M, std::move(L), std::move(R));
    return 0;
}
