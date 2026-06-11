#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    int n, m, q; cin >> n >> m >> q;
    vector<vector<int>> x(n, vector<int>(n,0));
    vector<vector<int>> c(n+1, vector<int>(n+1,0));
    rep(i,m){
        int l, r; cin >> l >> r;
        --l, --r;
        x[l][r]++;
    }
    rep(i,n)rep(j,n) c[i][j+1] = c[i][j] + x[i][j];//c[l][r] = [l,r)の和, x[l][r] = [l,r]の個数
    rep(i,q){
        int p, q; cin >> p >> q;
        --p, --q;
        int sum = 0;
        for(int i = p; i <= q; ++i) sum += c[i][q+1] - c[i][p];
        cout << sum << endl;
    }
}