#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};
int H,W;

bool check(vector<string>S,int x,int y){
    if(S[y][x]=='.') return true;
    for(int i=0;i<4;i++){
        int nx,ny;
        nx = x+dx[i];
        ny = y+dy[i];
        if(nx>=0&&nx<W&&ny>=0&&ny<H){
            if(S[ny][nx]=='#') return true;
        }
    }
    return false;
}

int main(){
    cin >> H >> W;
    vector<string> S(H);
    rep(i,H) cin >> S[i];
    bool flg = true;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            flg = check(S,j,i);
            if(!flg){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    if(flg) cout <<"Yes"<<endl;
    return 0;
}