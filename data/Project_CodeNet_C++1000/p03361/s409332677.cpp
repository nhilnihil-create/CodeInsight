#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    int H, W;
    cin >> H >> W;
    vector<string> a(H);
    typedef pair<int, int> trans;
    vector<trans> Trans{trans(-1, 0),trans(1, 0),trans(0, -1),trans(0, 1)};
    rep(i,H)cin>>a[i];
    
    rep(i,H){
        for(int j=0; j<W; j++){
            char c = a[i][j];
            if(c=='.')continue;

            int x, y;
            bool is_paint = false;
            for(trans xy: Trans){
                x = j + xy.first;
                y = i + xy.second;

                if(x >= 0 && x < W && y >= 0 && y < H){
                    if(a[y][x] == '#'){
                        is_paint = true;
                    }
                }
            }

            if(is_paint == false){
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
    return 0;
}