#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int N,M;
    cin >> N >> M;
    vector<int>X(M);
    for(int i = 0; i < M; i++) {
        cin >> X[i];
    }
    sort(X.begin(),X.end());
    vector<int>Y(M-1);
    for(int i = 0; i < M-1; i++) {
        Y[i] = X[i+1]-X[i];
    }
    sort(Y.begin(),Y.end());
    int ans = X[M-1]-X[0];
    for(int i = 0; i < min(N-1,M-1); i++) {
        ans-=Y[M-2-i];
    }
    cout << ans << endl;
}

