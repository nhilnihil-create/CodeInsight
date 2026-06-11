#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int H, W;
    cin >> H >> W;

    vector<vector<int> > a(H, vector<int>(W));
    vector<int> c(H);

    vector<vector<int> > ans;

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> a[i][j];
            if(a[i][j] % 2) c[i]++;
        }
    }

    for(int i = 0; i < H; i++) {
        bool re = false;
        for(int j = 0; j < W - 1; j++) {
            if(a[i][j] % 2) re = !re;
            if(re) {
                vector<int> x(4);
                x[0] = i + 1;
                x[1] = j + 1;
                x[2] = i + 1;
                x[3] = j + 2;
                ans.push_back(x);
            }
        }
    }

    bool re = false;

    for(int i = 0; i < H - 1; i++) {
        if(c[i] % 2) re = !re;
        if(re) {
            vector<int> x(4);
            x[0] = i + 1;
            x[1] = W;
            x[2] = i + 2;
            x[3] = W;
            ans.push_back(x);
        }
    }

    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << " " << ans[i][3] << endl;
    }
}