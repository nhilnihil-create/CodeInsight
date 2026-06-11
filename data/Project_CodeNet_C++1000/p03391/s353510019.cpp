#include<bits/stdc++.h>
#define ALL(c) (c).begin(),(c).end()
#define EACH(i,c) for(auto i=(c).begin();i!=(c).end();++i)
using namespace std;
#define int long long


void solve(long long N, std::vector<long long> A, std::vector<long long> B){
    if(A == B) {
        cout << 0 << endl;
        return;
    }
    int res = 0, mn = (int)1e10;
    for(int i = 0; i < N; ++i) {
        res += A[i];
        if (A[i] > B[i]) {
            mn = min(mn, B[i]);
        }
    }
    cout << res - mn << endl;
}

signed main(){
	ios::sync_with_stdio(false);
    long long N;
    scanf("%lld",&N);
    std::vector<long long> A(N);
    std::vector<long long> B(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
        scanf("%lld",&B[i]);
    }
    solve(N, std::move(A), std::move(B));
    return 0;
}