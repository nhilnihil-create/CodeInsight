#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int X, Y, Z, K; cin >> X >> Y >> Z >> K;
    vector<ll> A(X), B(Y), C(Z);
    rep(i, X){
        cin >> A[i];
    }
    rep(i, Y){
        cin >> B[i];
    }
    rep(i, Z){
        cin >> C[i];
    }
    vector<ll> AB;
    rep(i, X){
        rep(j, Y){
            AB.push_back(A[i] + B[j]);
        }
    }
    sort(AB.begin(), AB.end(), greater<ll>());
    vector<ll> ans;
    int a = AB.size();
    a = min(a, K);
    rep(i, a){
        rep(j, Z){
            ans.push_back(AB[i] + C[j]);
        }
    }
    sort(ans.begin(), ans.end(), greater<ll>());
    rep(i, K){
        cout << ans[i] << endl;
    }



    return 0;
}