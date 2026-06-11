#include<bits/stdc++.h>

using namespace std;
using ll=long long;

int t;

const int mod=1e9+7;

void add_self(int &a, int b){
    a+=b;
    if(a>=mod)a-=mod;
}

void test_case(){
    int h,w;
    cin>>h>>w;
    vector<vector<char>>grid(h,vector<char>(w));
    vector<vector<int>>dp(h,vector<int>(w));
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin>>grid[i][j];
        }
    }
    dp[0][0]=1;
    for(int row=0; row<h; row++){
        for(int col=0; col<w; col++){
            if(col<w-1&&grid[row][col+1]=='.'){
                add_self(dp[row][col+1], dp[row][col]);
            }
            if(row<h-1&&grid[row+1][col]=='.'){
                add_self(dp[row+1][col], dp[row][col]);
            }
        }
    }
    cout<<dp[h-1][w-1]<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    t=1;
    while(t--){
        test_case();
    }

    return 0;
}