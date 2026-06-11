#include <bits/stdc++.h>
using namespace std;

//#define int long long
typedef long long ll;
//const int INF = 2e9;
//const ll INF = 9e18;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int H, W;
    cin >> H >> W;
    vector<vector<int>> a(H,vector<int>(W));
    for (int h=0;h<H;h++){
        for (int w=0;w<W;w++){
            int p;
            cin >> p;
            a[h][w] = p % 2;
        }
    }
    vector<pair<pair<int,int>,pair<int,int>>> ans;
    for (int w=0;w<W;w++){
        for (int h=0;h<H-1;h++){
            if (a[h][w]==1){
                ans.push_back(make_pair(make_pair(h,w),make_pair(h+1,w)));
                a[h][w]=0;
                a[h+1][w] = (a[h+1][w] + 1)%2; 
            }
        }
    }
    for (int w=0;w<W-1;w++){
        if (a[H-1][w]==1) {
            ans.push_back(make_pair(make_pair(H-1,w),make_pair(H-1,w+1)));
            a[H-1][w]=0;
            a[H-1][w+1] = (a[H-1][w+1] + 1)%2;
        }
    }
    cout << ans.size() << "\n";
    for (int i=0;i<ans.size();i++){
        cout << ans[i].first.first + 1 << " " << ans[i].first.second + 1;
        cout << " " << ans[i].second.first + 1 << " " << ans[i].second.second + 1 << "\n";
    }
}