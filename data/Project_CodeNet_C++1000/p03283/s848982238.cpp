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
    int N, M, Q; cin >> N >> M >> Q;
    vector<int> L(M), R(M);
    rep(i,M) cin >> L[i] >> R[i];


    vector<vector<int>> S(N+1, vector<int>(N+1,0));
    rep(i,M) S[L[i]][R[i]]++;

    rep(i,N){
        rep(j,N){
            S[i+1][j+1] += S[i][j+1] + S[i+1][j] - S[i][j]; 
        }
    }

    vector<int> p(Q), q(Q);
    rep(i,Q) cin >> p[i] >> q[i];

    rep(i,Q){
        int ans = S[q[i]][q[i]] - S[q[i]][p[i]-1] - S[p[i]-1][q[i]] + S[p[i]-1][p[i]-1];
        printf("%d\n", ans);
    }
}