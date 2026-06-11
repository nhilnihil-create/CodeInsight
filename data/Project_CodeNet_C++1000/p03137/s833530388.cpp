#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N, M; cin >> N >> M;
    vector<int> X(M);
    rep(i, M){
        cin >> X[i];
    }
    sort(X.begin(), X.end());
    vector<int> D;
    for (int i = 1; i < M; i++){
        int d = X[i] - X[i-1];
        D.push_back(d);
    }
    sort(D.begin(), D.end());
    ll ans = 0;
    for (int i = 0; i < M-1-N+1; i++){
        ans += D[i];
    }

    cout << ans << endl;
    

    return 0;
}