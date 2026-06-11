// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define Graph vector<vector<int>>
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1000000007;

int main(){
    int X, Y, Z, K;
    cin >> X >> Y >> Z >> K;
    vector<ll> A(X), B(Y), C(Z);
    rep(i, X) cin >> A[i];
    rep(i, Y) cin >> B[i];
    rep(i, Z) cin >> C[i];

    sort(all(A));
    reverse(all(A));
    sort(all(B));
    reverse(all(B));
    sort(all(C));
    reverse(all(C));

    vector<ll> ans;

    rep(i, X){
        rep(j, Y){
            rep(k, Z){
                if((i + 1) * (j + 1) * (k + 1) <= K){
                    ans.push_back(A[i] + B[j] + C[k]);
                } 
            }
        }
    }

    sort(all(ans));
    reverse(all(ans));

    rep(i, K){
        cout << ans[i] << endl;
    }

}