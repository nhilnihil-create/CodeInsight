#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (int i=0; i<n; ++i)
#define all(obj) (obj).begin(),(obj).end()
using namespace std;
typedef long long ll;

int main(){
    int N, a2;
    cin >> N;
    vector<vector<int>> A(2, vector<int>(N));
    rep(i, 2){
        rep(j, N) cin >> A[i][j];
    }
    rep(i, N) a2 += A[1][i];
    int ans = A[0][0]+a2;
    int su = ans;
    rep(i, N-1){
        su = su+A[0][i+1]-A[1][i];
        ans = max(ans, su);
    }
    cout << ans << endl;
    return 0;
}
