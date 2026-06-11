#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define sc(x) scanf("%d",&x);
int h, w;
vector<vector<int> > G;
vector<P> ans;
int main(){
    sc(h) sc(w)
    G.resize(h);
    for (int i = 0; i < h; i++) G[i].resize(w);
    for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) sc(G[i][j])
    for (int i = 1; i <= h; i++) for (int j = 1; j <= w; j++) if (G[i-1][j-1]%2){
        if (j != w) ans.push_back(P(i, j)), ans.push_back(P(i, j+1)), G[i-1][j]++;
        else if (i != h) ans.push_back(P(i, j)), ans.push_back(P(i+1, j)), G[i][j-1]++;
    }
    cout << ans.size() / 2 << endl;
    for (int i = 0; i < ans.size(); i++){
        if (i % 2 == 0) cout << ans[i].first << " " << ans[i].second << " ";
        else cout << ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
}