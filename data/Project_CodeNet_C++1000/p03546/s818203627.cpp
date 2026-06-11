#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0 ,-1};
signed main(){
    int H,W;
    cin >> H >> W;
    vector<vector<int>>c(10,vector<int>(10));
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cin >> c[i][j];
        }
    }
    vector<int>cnt(10);
    iota(cnt.begin(),cnt.end(),0);
    vector<int>cnt2(10,INF);
    do{
        int sum = 0;
        for(int i = 0; i < 10; i++) {
            if(i) {
                sum+=c[cnt[i-1]][cnt[i]];
            }
            if(cnt[i] == 1) {
                break;
            }
        }
        cnt2[cnt[0]] = min(cnt2[cnt[0]],sum);
    } while (next_permutation(cnt.begin(),cnt.end()));
    int ans = 0;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            int A;
            cin >> A;
            if(A == -1) {
                continue;
            }
            ans+=cnt2[A];
        }
    }
    cout << ans << endl;
}