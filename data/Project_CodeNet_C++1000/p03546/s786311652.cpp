#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )
#define FOR(i, m, n) for(int i = m; i < n; i++)
 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int step;

void dfs(vector<vector<int>> &C, set<int> &s, int i, int j) {
    s.insert(i);
    if (i==1) {
        step = min(step,j);
    }
    else {
        rep(k,10){
            if (s.count(k)) continue;
            else {
                dfs(C,s,k,j+C[i][k]);
            }
            s.erase(k);
        }
    }

}

int main(){
    int H,W;
    cin >> H >> W;
    vector<vector<int>> C(10 ,vector<int>(10));

    rep(i,10) {
        rep(j,10) {
            cin >> C[i][j];
        }
    }

    vector<ll> M(10);
    rep(i,10) {
        set<int> s;
        step = INF;
        dfs(C,s,i,0);
        M[i] = step;
    }

    vector<int> A;
    rep(i,H*W) {
        int a;
        cin >> a;
        if (a!=-1) {
            A.push_back(a);
        }
    }

    ll ans = 0;

    rep(i,A.size()) {
        ans += M[A[i]];
    }
    cout << ans << endl;

}