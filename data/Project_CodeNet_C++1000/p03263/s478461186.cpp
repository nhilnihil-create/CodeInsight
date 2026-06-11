#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define f first
#define s second
using namespace std;
int h, w, a[600][600];
vector<pair<int,int>> vec1, vec2;
pair<pair<int,int>, int> fun(int x, int y, int dir){
    pair<pair<int,int>, int> ret;
    if(dir == 1){
        if(y+1 <= w){
            ret.f.f = x; ret.f.s = y+1; ret.s = dir;
        }
        else{
            ret.f.f = x+1; ret.f.s = w; ret.s = -1*dir;
        }
    }
    else{
        if(y-1 >= 1){
            ret.f.f = x; ret.f.s = y-1; ret.s = dir;
        }
        else{
            ret.f.f = x+1; ret.f.s = 1; ret.s = -1*dir;
        }
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin >> h >> w;
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            cin >> a[i][j];
        }
    }
    int cx = 1, cy = 1;
    int cnt = 0;
    int dir = 1;
    int dis = 0;
    while(1){
        dis++;
        //cout << dis << " " << cx << " " << cy << endl;
        if(dis == h*w)break;
        pair<pair<int,int>, int> nxt = fun(cx, cy, dir);
        if(a[cx][cy]&1){
            cnt++;
            vec1.pb({cx,cy}); vec2.pb({nxt.f.f, nxt.f.s});
            a[nxt.f.f][nxt.f.s]++;
        }
        cx = nxt.f.f; cy = nxt.f.s; dir = nxt.s;
    }
    cout << cnt << '\n';
    for(int i = 0; i < vec1.size(); i++){
        cout << vec1[i].f << " " << vec1[i].s << " " << vec2[i].f << " " << vec2[i].s << '\n';
    }
    return 0;
}
