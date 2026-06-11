#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
 
const ll INF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;
typedef priority_queue<int, vector<int>, greater<int>> PQ;
const int MOD = 1000000007;

int main(){
    int X, Y, Z, K; cin >> X >> Y >> Z >> K;
    vector<ll> A(X), B(Y), C(Z);
    rep(i,X) cin >> A[i];
    rep(i,Y) cin >> B[i];
    rep(i,Z) cin >> C[i];

    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    sort(C.rbegin(), C.rend());

    vector<ll> ABC;
    rep(i,X){
        rep(j,Y){
            if ((i+1)*(j+1) > K) break;
            rep(k,Z){
                if ((i+1)*(j+1)*(k+1) > K) break;
                ABC.push_back(A[i]+B[j]+C[k]);
            }
        }
    }
    sort(ABC.rbegin(), ABC.rend());

    rep(i,K) cout << ABC[i] << endl;
}