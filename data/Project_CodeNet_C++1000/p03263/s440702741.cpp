#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define sc(x) scanf("%d",&x);
int h, w;
vector<vector<int> > G;
vector<vector<bool> > Used;
vector<int> mx = {0, 0, -1, 1}, my = {1, -1, 0, 0};
int main(){
    int x;
    sc(h) sc(w)
    G.resize(h);
    for (int i = 0; i < h; i++) G[i].resize(w);
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++) sc(G[i][j])
    }
    vector<P> ans;
    for (int i = 0; i < h; i++){
        if (i % 2 == 0){
            for (int j = 0; j < w; j++){
                if (G[i][j] % 2 == 1){
                    if (j == w-1 && i != h-1){
                        ans.push_back(P(i+1, j+1));
                        ans.push_back(P(i+2, w));
                        G[i+1][w-1] += 1;
                    }else if (j != w-1){
                        ans.push_back(P(i+1, j+1));
                        ans.push_back(P(i+1, j+2));
                        G[i][j+1] += 1;
                    }
                }
            }
        }else{
            for (int j = w-1; j >= 0; j--){
                if (G[i][j] % 2 == 1){
                    if (j == 0 && i != h-1){
                        ans.push_back(P(i+1, j+1));
                        ans.push_back(P(i+2, 1));
                        G[i+1][0] += 1;
                    }else if (j != 0){
                        ans.push_back(P(i+1, j+1));
                        ans.push_back(P(i+1, j));
                        G[i][j-1] += 1;
                    }
                }
            }
        }
    }
    cout << ans.size() / 2 << endl;
    for (int i = 0; i < ans.size(); i++){
        if (i % 2 == 0) cout << ans[i].first << " " << ans[i].second << " ";
        else cout << ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
}