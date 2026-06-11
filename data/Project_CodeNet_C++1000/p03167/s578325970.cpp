#include <bits/stdc++.h>
using namespace std;

#define M 1000000007

int grid(vector<vector<char>> v,int r, int c){
    long long dp[r][c];
    bool flag=0;
    for(int i=0; i<r; i++){
        if(v[i][0]=='#') flag=1;
        if(flag==0) dp[i][0]=1;
        else dp[i][0]=0;
    }
    flag=0;
    for(int i=0; i<c; i++){
        if(v[0][i]=='#') flag=1;
        if(flag==0) dp[0][i]=1;
        else dp[0][i]=0;
    }
    for(int i=1; i<r; i++){
        for(int j=1; j<c; j++){
            if(v[i][j]=='#') dp[i][j]=0;
            else dp[i][j]= (dp[i-1][j]%M+dp[i][j-1]%M)%M;
        }
    }
    return dp[r-1][c-1]%M;
}

int main(){
    int r,c;
    cin>>r>>c;
    vector<vector<char>> v(r, vector<char>(c));
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++) cin>>v[i][j];
    cout<<grid(v, r, c);
    return 0;
}
