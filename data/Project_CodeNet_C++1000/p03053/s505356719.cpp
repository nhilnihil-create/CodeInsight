#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

int main(){
    int H, W;
    cin >> H >> W;
    vector<vector<int>> G(H, vector<int> (W, inINF));
    char c;

    queue<iint> q;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> c;
            if(c == '#'){
                G[i][j] = 0;
                q.push(make_pair(i, j));
            }
        }
    }

    int v, w;
    vector<int> x(4), y(4);
    x[0] = 1;
    x[1] = -1;
    x[2] = 0;
    x[3] = 0;
    y[0] = 0;
    y[1] = 0;
    y[2] = 1;
    y[3] = -1;
    while(!q.empty()){
        v = q.front().first;
        w = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            if(v+x[i] < H && v+x[i] >= 0 && w+y[i] < W && w+y[i] >= 0 && G[v+x[i]][w+y[i]] == inINF){
                G[v+x[i]][w+y[i]] = G[v][w] + 1;
                q.push(make_pair(v+x[i], w+y[i]));
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            ans = max(ans, G[i][j]);
        }
    }

    printf("%d\n", ans);



}