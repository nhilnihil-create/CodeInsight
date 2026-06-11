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
    vector<vector<int>> a(H, vector<int> (W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> a[i][j];
        }
    }

    vector<pair<iint,iint>> ans;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W-1; j++) {
            if(a[i][j] % 2 == 1){
                ans.push_back(make_pair(make_pair(i+1, j+1), make_pair(i+1, j+2)));
                a[i][j]--;
                a[i][j+1]++;
            }
        }
    }
    for (int i = 0; i < H-1; i++) {
        if(a[i][W-1] % 2 == 1){
            ans.push_back(make_pair(make_pair(i+1, W), make_pair(i+2, W)));
            a[i][W-1]--;
            a[i+1][W-1]++;
        }
    }

    int M;
    M = ans.size();
    printf("%d\n", M);

    for (int i = 0; i < M; i++) {
        printf("%d %d %d %d\n", ans[i].first.first, ans[i].first.second, ans[i].second.first, ans[i].second.second);
    }

}