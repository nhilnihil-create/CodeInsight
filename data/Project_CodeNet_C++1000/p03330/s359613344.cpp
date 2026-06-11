#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a) (a).begin(),(a).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n,c; cin >> n >> c;
    vector<vector<int>> d(c);
    rep(i,c){
        rep(j,c){
            int D; cin >> D;
            d[i].push_back(D);
        }
    }
    vector<vector<int>> C(n);
    rep(i,n)rep(j,n){
        int x; cin >> x;
        x--;
        C[i].push_back(x);
    }
    vector<int> team0,team1,team2;
    rep(i,n)rep(j,n){
        if((i+j)%3 == 0) team0.push_back(C[i][j]);
        if((i+j)%3 == 1) team1.push_back(C[i][j]);
        if((i+j)%3 == 2) team2.push_back(C[i][j]);
    }
    vector<vector<int>> table(3);
    rep(i,c){
        int sum0 = 0,sum1 = 0,sum2 = 0;
        for(int x : team0) sum0 += d[x][i];
        for(int x : team1) sum1 += d[x][i];
        for(int x : team2) sum2 += d[x][i];
        table[0].push_back(sum0);
        table[1].push_back(sum1);
        table[2].push_back(sum2);
    }
    int ans = 1e9;
    rep(i,c)rep(j,c)rep(k,c){
        if(i == j || j == k || k == i) continue;
        ans = min(ans,table[0][i]+table[1][j]+table[2][k]);
    }
    cout << ans << endl;
}