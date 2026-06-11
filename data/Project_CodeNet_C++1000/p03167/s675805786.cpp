#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const int maxN = 1e5+5;
const int mod = 1e9+7;

void solve(){
    int H,W;
    cin>>H>>W;
    vector<string> grid(H);
    for(int i=0;i<H;i++){
        cin>>grid[i];
    }

    int mat[H+1][W+1];
    mat[0][0] = 1;
    for(int i=1;i<H;i++){
        if(grid[i][0]!='#')
            mat[i][0] = mat[i-1][0];
        else
            mat[i][0] = 0;
    }
    for(int i=1;i<W;i++){
        if(grid[0][i]!='#')
            mat[0][i] = mat[0][i-1];
        else
            mat[0][i] = 0;
    }
    for(int i=1;i<H;i++){
        for(int j=1;j<W;j++){
            if(grid[i][j]=='#') mat[i][j] = 0;
            else mat[i][j] = (mat[i-1][j]+mat[i][j-1])%mod;
        }
    }
    cout<<mat[H-1][W-1]<<endl;
}

int main()
{
    FASTIO
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}


