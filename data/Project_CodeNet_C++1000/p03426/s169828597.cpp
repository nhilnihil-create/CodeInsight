// AtCoder template
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0; i < n; ++i)

struct Vector2{
    int y,x;
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int h,w,d; cin >> h >> w >> d;
    int a[h][w];
    Vector2 p[h*w]; rep(i,h) rep(j,w){
        cin >> a[i][j];
        --a[i][j];
        p[a[i][j]] = Vector2({i,j});
    }
    map<int, int> score;
    rep(i, h*w){
        if(i+d >= h*w) continue;
        score[i+d] += score[i] + abs(p[i+d].y-p[i].y) + abs(p[i+d].x - p[i].x);
    }
    int q,l,r; cin >> q;
    rep(i,q){
        cin >> l >> r;
        --l; --r;
        cout << score[r] - score[l] << "\n";
    }
}