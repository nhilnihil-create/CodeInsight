#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    vector<vector<int>> ans(h, vector<int>(w));
    for(int i = 0; i < h; i++){
        cin >> s[i];
    }

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(s[i][j] == '#'){
                ans[i][j] = -1;
                continue;
            }
            int sum = 0;
            for(int dy = -1; dy <= 1; dy++){
                for(int dx = -1; dx <= 1; dx++){
                    if((dx == 0) && (dy == 0)) continue;
                    if((i + dy < 0) || (i + dy >= h)) continue;
                    if((j + dx < 0) || (j + dx >= w)) continue;
                    if(s[i+dy][j+dx] == '#') sum++;
                }
            }
            ans[i][j] = sum;
        }
    }
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(ans[i][j] == -1) cout << '#';
            else cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}