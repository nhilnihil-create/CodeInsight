/**
*    author:  souzai32
*    created: 21.08.2020 00:15:18
**/

#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
typedef long long ll;
using namespace std;

int main() {

    int h,w;
    cin >> h >> w;
    vector<vector<char>> s(h,vector<char>(w));
    vector<vector<bool>> t(h,vector<bool>(w));
    vector<vector<int>> d(h,vector<int>(w));
    int num=0;
    rep(i,h){
        rep(j,w){
            cin >> s.at(i).at(j);
            if(s.at(i).at(j)=='.') num++;
        }
    }
    queue<int> qh,qw;
    int x,y;

    if(s.at(0).at(0)=='#' || s.at(h-1).at(w-1)=='#') cout << -1 << endl;
    else{
        qh.push(0);
        qw.push(0);
        t.at(0).at(0)=true;
        while(!qh.empty()){
            x=qh.front(); y=qw.front();
            qh.pop(); qw.pop();
            if(x!=0){
                if(s[x-1][y]=='.'&&!t[x-1][y]){
                    t[x-1][y]=true;
                    qh.push(x-1);
                    qw.push(y);
                    d[x-1][y]=d[x][y]+1;
                }
            }if(y!=0){
                if(s[x][y-1]=='.'&&!t[x][y-1]){
                    t[x][y-1]=true;
                    qh.push(x);
                    qw.push(y-1);
                    d[x][y-1]=d[x][y]+1;
                }
            }if(x!=h-1){
                if(s[x+1][y]=='.'&&!t[x+1][y]){
                    t[x+1][y]=true;
                    qh.push(x+1);
                    qw.push(y);
                    d[x+1][y]=d[x][y]+1;
                }
            }
            if(y+1<w){
                if(s.at(x).at(y+1)=='.'&&!t.at(x).at(y+1)){
                    t[x][y+1]=true;
                    qh.push(x);
                    qw.push(y+1);
                    d[x][y+1]=d[x][y]+1;
                }
            }
        }
        if(d[h-1][w-1]) cout << num-d[h-1][w-1]-1 << endl;
        else cout << -1 << endl;
        // rep(i,h){
        //     rep(j,w) cout << d[i][j];
        //     cout << endl;
        // }
    }



    return 0;
}