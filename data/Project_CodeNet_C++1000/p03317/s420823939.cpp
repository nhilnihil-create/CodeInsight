#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(long long N, long long K, std::vector<long long> A){
    ll ans = 0;
    ll right = 0;
    while(true){
        if(right == 0) right += K;
        else right += K - 1;
        ans ++;
        if(right >= N) break;
    }
    cout << ans << endl;
    return;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long K;
    scanf("%lld",&K);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, K, std::move(A));
    return 0;
}
