/**
*    author:  souzai32
*    created: 21.08.2020 00:48:22
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
    vector<vector<char>> a(h,vector<char>(w));
    vector<vector<bool>> t(h,vector<bool>(w));
    vector<vector<int>> d(h,vector<int>(w));
    queue<tuple<int,int,int>> que;
    rep(i,h){
        rep(j,w){
            cin >> a[i][j];
            if(a[i][j]=='#'){
                que.push(tuple<int,int,int>(i,j,-1));
                t[i][j]=true;
            }
        }
    }

    tuple<int,int,int> p;
    int i=0;
    while(!que.empty()){
        p=que.front();
        que.pop();
        int x=get<0>(p),y=get<1>(p),z=get<2>(p)+1;
        d[x][y]=z;
        if(x-1>=0){
            if(!t[x-1][y]){
                que.push(tuple<int,int,int>(x-1,y,z));
                t[x-1][y]=true;
            }
        }if(x+1<h){
            if(!t[x+1][y]){
                que.push(tuple<int,int,int>(x+1,y,z));
                t[x+1][y]=true;
            }
        }if(y-1>=0){
            if(!t[x][y-1]){
                que.push(tuple<int,int,int>(x,y-1,z));
                t[x][y-1]=true;
            }
        }if(y+1<w){
            if(!t[x][y+1]){
                que.push(tuple<int,int,int>(x,y+1,z));
                t[x][y+1]=true;
            }
        }
        i++;
        if(i==1e8) break;
    }

    // cout << endl;
    // rep(i,h){
    //     rep(j,w) cout << d[i][j];
    //     cout << endl;
    // }
    int ans=0;
    rep(i,h){
        rep(j,w) ans=max(ans,d[i][j]);
    }
    cout << ans << endl;

    return 0;
}