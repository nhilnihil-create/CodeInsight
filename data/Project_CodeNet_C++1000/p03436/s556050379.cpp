#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <iomanip>
#include <map>
#include <queue>
#include <tuple>

using namespace std;

typedef long long ll;
typedef tuple<int,int,int> P;


int main(){
    int H,W;
    cin >> H >> W;
    vector<vector <char> > tile(H+2,vector<char>(W+2,'#'));
    int ans=0;
    for(int i=1; i<=H; i++){
        for(int j=1; j<=W; j++){
            cin >> tile[i][j];
            if(tile[i][j]=='.') ans++;
        }
    }

    
    queue<P> que;
    que.push(P(1,1,1));
    int inf=1e9;
    vector<vector <int> > out(H+2,vector<int>(W+2,inf));
    while(!que.empty()){
        P now=que.front();que.pop();

        int h=get<0>(now),w=get<1>(now),d=get<2>(now);
        if(out[h][w]<=d) continue;
        out[h][w]=d;
        if(tile[h+1][w]=='.') que.push(P(h+1,w,d+1));
        if(tile[h][w+1]=='.') que.push(P(h,w+1,d+1));
        if(tile[h-1][w]=='.') que.push(P(h-1,w,d+1));
        if(tile[h][w-1]=='.') que.push(P(h,w-1,d+1));
    }
    
    if(out[H][W]==inf) ans=-1;
    else ans-=out[H][W];

    cout << ans << endl;




    return 0;
}