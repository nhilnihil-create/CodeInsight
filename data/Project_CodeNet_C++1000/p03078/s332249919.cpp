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

    vector<ll> AB;
    rep(i, X){
        rep(j, Y){
            AB.push_back(A[i] + B[j]);
        }
    }

    sort(all(AB));
    reverse(all(AB));

    vector<ll> ABC;
    int W = AB.size();
    W = min(W, K);
    
    rep(i, W){
        rep(j, Z){
            ABC.push_back(AB[i] + C[j]);
        }
    }

    sort(all(ABC));
    reverse(all(ABC));

    rep(i, K){
        cout << ABC[i] << endl;
    }

}