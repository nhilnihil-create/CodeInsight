#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;

typedef P<int, int> pint;
typedef P<pint, pint> ppint;

int main() {
    int H, W; cin >> H >> W;

    int odd = 0;
    V<V<int> > b(H, V<int>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> b[i][j];
            if(b[i][j] & 1) odd++;
        }
    }

    V<ppint> ans;
    int num = 0, h = 0, w = 0;
    for(int i = 0; i < H * W; i++){
        if(b[h][w] & 1) num++;

        // ジグザグ移動
        int nh = h, nw = w;
        if(h % 2 == 0){
            if(nw == W - 1) nh++;
            else nw++;
        }else{
            if(nw == 0) nh++;
            else nw--;
        }

        if(num & 1 && num < odd){
            ans.push_back(ppint(pint(h, w), pint(nh, nw)));
        }
        h = nh, w = nw;
    }

    cout << ans.size() << endl;
    for(auto p : ans){
        cout << p.first.first + 1 << " " << p.first.second +1 << " ";
        cout << p.second.first + 1 << " " << p.second.second +1 << endl;
    }



}
