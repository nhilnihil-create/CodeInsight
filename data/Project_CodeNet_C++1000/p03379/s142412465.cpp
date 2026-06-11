#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(long long N, std::vector<long long> X){
    vector<ll> x = X;
    sort(x.begin(), x.end());
    for(ll i = 0; i < N; ++i){
        if(X[i] < x[N/2]) cout << x[N/2] << endl;
        else cout << x[N/2-1] << endl;
    }
    return;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> X(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&X[i]);
    }
    solve(N, std::move(X));
    return 0;
}
