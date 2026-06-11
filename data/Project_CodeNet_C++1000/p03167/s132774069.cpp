#include<iostream>
#define MOD 1000000007
using namespace std;

char maze[1001][1001];
int dp[1001][1001];
int H,W;

void add(int &a,int b){
    a += b;
    if(a >= MOD) a -= MOD;
}

int main(){
    cin >> H >> W;
    for(int i=0;i < H;i++){
        for(int j=0;j < W;j++){
            cin >> maze[i][j];
        }
    }
    
    dp[0][0] = 1;

    for(int i=0;i < H;i++){
        for(int j=0;j < W;j++){
            if(i+1 < H && maze[i+1][j] == '.'){
                add(dp[i+1][j],dp[i][j]);
            }
            if(j+1 < W && maze[i][j+1] == '.'){
                add(dp[i][j+1],dp[i][j]);
            }
        }
    }
    cout << dp[H-1][W-1] << endl;
    return 0;
}