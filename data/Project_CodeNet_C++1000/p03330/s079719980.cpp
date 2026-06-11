#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T, class U> using Pa = pair<T, U>;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,C;
    cin >> N >> C;
    vvec<int> D(C,vec<int>(C));
    for(int i=0;i<C;i++) for(int j=0;j<C;j++) cin >> D[i][j];
    vvec<int> A(N,vec<int>(N));
    vvec<int> sum(3,vec<int>(C));
    for(int i=0;i<N;i++) for(int j=0;j<N;j++){
        cin >> A[i][j];
        A[i][j]--;
        for(int k=0;k<C;k++) sum[(i+j)%3][k] += D[A[i][j]][k];
    }
    int ans = 2e9;
    for(int i=0;i<C;i++) for(int j=0;j<C;j++) for(int k=0;k<C;k++){
        if(i==j || j==k || k==i) continue;
        ans = min(ans,sum[0][i]+sum[1][j]+sum[2][k]);
    }
    cout << ans << "\n";
}