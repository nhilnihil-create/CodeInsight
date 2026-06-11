#include <bits/stdc++.h>
using namespace std;

//#define int long long
typedef long long ll;
//const int INF = 2e9;
//const ll INF = 9e18;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int H, W, D;
    cin >> H >> W >> D;
    vector<pair<int,int>> p(H*W);
    for (int h=0;h<H;h++){
        for (int w=0;w<W;w++){
            int a;
            cin >> a;
            a--;
            p[a] = make_pair(h,w);
        }
    }
    vector<int> step(H*W);
    for (int i=H*W-1;i>=0;i--){
        if (i+D >= H*W) step[i] = 0;
        else step[i] = step[i+D] + abs(p[i+D].first - p[i].first) + abs(p[i+D].second - p[i].second);
    }
    int Q;
    cin >> Q;
    for (int i=0;i<Q;i++){
        int L, R;
        cin >> L >> R;
        L--;R--;
        cout << step[L] - step[R] << "\n";
    }
}