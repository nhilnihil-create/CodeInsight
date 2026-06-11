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
    int H, W, D;
    cin >> H >> W >> D;

    //vector<vector<int>> A(H, vector<int>(W));
    //rep(i,H) rep(j,W) cin >> A[i][j];
    map<int, pair<int, int>> positions;
    rep(i,H){
        rep(j,W){
            int a; cin >> a;
            pair<int, int> p = make_pair(i,j);
            positions[a] = p;
        }
    }    
    vector<int> C(H*W+1,0);
    rep(i,D){
        int index = i + D;
        while(index <= H*W){
            int x = abs(positions[index].first-positions[index-D].first);
            int y = abs(positions[index].second-positions[index-D].second);   
            C[index] = x + y + C[index-D];             
            index += D;
        }
    }

    int Q; cin >> Q;
    vector<int> L(Q), R(Q);
    rep(i,Q) cin >> L[i] >> R[i];

    rep(i,Q){
        printf("%d\n", C[R[i]] - C[L[i]]);
    }


}