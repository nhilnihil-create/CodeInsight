#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define mat vector<vector<int>>
const int inf = 1 << 30;
const ll linf = 1e18;
const db EPS = 1e-7;
template<class T> void chmin(T& x, T y){if(x > y) x = y;}
template<class T> void chmax(T& x, T y){if(x < y) x = y;}

int H, W;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int cnt[1010][1010];
char A[1010][1010];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> H >> W;

    queue<pii> q;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> A[i][j];
            cnt[i][j] = inf;
            if(A[i][j] == '#') cnt[i][j] = 0, q.push({i, j});
        }
    }
    int ans = 0;
    while(!q.empty()){
        pii p = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int rh = p.first + dx[i];
            int rw = p.second + dy[i];
            if(0 <= rh && rh < H && 0 <= rw && rw < W && cnt[rh][rw] > cnt[p.first][p.second] + 1){
                q.push({rh, rw});
                cnt[rh][rw] = cnt[p.first][p.second] + 1;
                chmax(ans, cnt[rh][rw]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}