#include <bits/stdc++.h>
#define ll long long
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

int main(){
    int H, W; cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W));
    queue<pair<int, int>> que;
    rep(i, H) rep(j, W){
        char tmp; cin >> tmp;
        if(tmp == '.'){
            A[i][j] = -1;
        }
        else if(tmp == '#'){
            A[i][j] = 0;
            que.push(pair<int, int>(i, j));
        }
    }
    int ans = 0;
    int hd[] = {0,1,0,-1}, wd[] = {1,0,-1,0};
    while(!que.empty()){
        int hs = que.front().first;
        int ws = que.front().second;
        rep(i, 4){
            int ht = hs + hd[i];
            int wt = ws + wd[i];
            if(ht < 0 || ht >= H || wt < 0 || wt >= W){
                continue;
            }
            if(A[ht][wt] == -1){
                A[ht][wt] = A[hs][ws] + 1;
                que.push(pair<int, int>(ht, wt));
                ans = max(ans, A[ht][wt]);
            }
        }
        que.pop();
    }
    cout << ans << endl;
    return 0;
}