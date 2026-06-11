#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T>
using vec = std::vector<T>;

int main() {
    int N;
    cin >> N;
    vec<vec<int>> A(2,vec<int>(N));
    rep(i,2)rep(j,N){
        cin >> A[i][j];
    }
    vec<int> U(N);
    vec<int> D(N);
    U[0] = A[0][0];
    D[0] = A[1][0];
    rep(i,N-1){
        U[i+1] = A[0][i+1]  + U[i];
        D[i+1] = A[1][i+1]  + D[i];
    }

    int ans = A[0][0]+D[N-1];
    for(int i=1;i<N;++i){
        int tmp = U[i] + D[N-1] - D[i-1];
        ans=max(ans,tmp);
    }
    cout << ans << endl;
}