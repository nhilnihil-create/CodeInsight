
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int h, w; cin >> h >> w;
    vector<string> s(h);
    rep(i,h){
        cin >> s.at(i);
    }
    //基準tなる座標からの周りの座標位置
    //右、上、左、下、右上、左上、左下、右下
    int dx[8] = {1,0,-1,0,1,-1,-1,1};
    int dy[8] = {0,1,0,-1,1,1,-1,-1};

    rep(i,h){
        rep(j,w){
            if(s[i][j] == '.'){
                int num=0;
                rep(d,8){
                    int ni = i + dx[d]; //基準座標の周りのx座標
                    int nj = j + dy[d]; //基準座標の周りのy座標

                    if(ni < 0 || h <= ni) continue; //座標の外なら無視
                    if(nj < 0 || w <= nj) continue; //座標の外なら無視
                    if(s[ni][nj] == '#') num++;
                }
                s[i][j] = num+'0'; //数値に文字列を足すと文字の数値に変換される
            }
        }
    }
    rep(i,h){
        cout << s[i] << endl;
    }



}