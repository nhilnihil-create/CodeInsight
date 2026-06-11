#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;

int dx[] = {1, -1, 0, 0};
int dy[] = {0 ,0, 1, -1};

int main(){
    int H, W;
    cin >> H >> W;
    Graph g(H, vector<int>(W)), g2(H, vector<int>(W, 0));
    rep(i, H){
        rep(j, W){
            char c;
            cin >> c;
            if(c == '.') g[i][j] = 0;
            else g[i][j] = 1;
        }
    }

    rep(i, H){
        rep(j, W){
            if(g[i][j] == 1){
                rep(k, 4){
                    if(i + dy[k] >= 0 && i + dy[k] < H && j + dx[k] >= 0 && j + dx[k] < W){
                        if(g[i + dy[k]][j + dx[k]] == 1){
                            g2[i][j] = 1;
                            g2[i + dy[k]][j + dx[k]] = 1;
                        }
                    }
                }
            }
        }
    }
    bool ans = true;
    rep(i, H){
        rep(j, W){
            if(g[i][j] != g2[i][j])ans = false;
        }
    }
    if(ans == true) cout << "Yes" << endl;
    else cout << "No" << endl;
}