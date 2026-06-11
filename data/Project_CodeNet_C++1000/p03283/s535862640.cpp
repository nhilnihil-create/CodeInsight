#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    int N,M,Q;
    cin >> N >> M >> Q;
    vector<vector<int> > vec(N + 1, vector<int>(N + 1));
    rep(i,N + 1){
        rep(j,N + 1){
            vec[i][j] = 0;
        }
    }
    rep(i,M){
        int l,r;
        cin >> l >> r;
        vec[l][r]++;
    }
    rep(i,N + 1){
        rep(j,N){
            vec[i][j + 1] += vec[i][j];
        }
    }
    vector<int> p(Q);
    vector<int> q(Q);
    rep(i,Q){
        cin >> p[i] >> q[i];
    }
    rep(i,Q){
        int ans = 0;
        for (int j = p[i]; j <= q[i]; j++){
            ans += vec[j][q[i]] - vec[j][p[i] - 1];
        }
        cout << ans << endl;
    }
}