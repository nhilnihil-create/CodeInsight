#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool dp(vector<int> dx, int X, int inix){
    int n = dx.size();
    int M = 8000;
    vector<vector<bool>> dp = vector<vector<bool>>(2*M+2, vector<bool>(n+1,false));
    dp[M+1+inix][0] = true;
    for(int i=1; i<=n; i++){
        for(int x=0; x<=2*M+1; x++){
            //cout << i << " " << x << " " << dp[x][i-1] << endl;
            if(dp[x][i-1]){
                dp[x+dx[i-1]][i] = true;
                dp[x-dx[i-1]][i] = true;
                // cout << i << ":" << x << " --> " << x+dx[i-1] << ", " << x-dx[i-1] << endl;
            }
        }
    }
    // cout << M << " " << X << " " << n << endl;
    // cout << X << " " << M+1+X << " " << dp[M+1+X][n] << endl;
    return dp[M+1+X][n];
}

int main(){
    string s;
    int x, y;
    cin >> s >> x >> y;
    int N = s.length();

    vector<int> dx, dy;
    dx.push_back(0);
    dy.push_back(0);
    bool goX = true;
    bool cntxini = true;
    int xini = 0;
    int cnt = 0;
    for(int i=0; i<N; i++){
        if(s[i]=='T' || i==N-1){
            if(s[i]=='F') cnt++;
            if(cntxini){
                xini = cnt;
                cntxini = false;
                cnt = 0;
                goX = false;
                continue;
            }
            if(goX) dx.push_back(cnt);
            else dy.push_back(cnt);
            cnt = 0;
            goX = !goX;
        }else{
            cnt++;
        }
    }

    // for(int i=0; i<dx.size()-1; i++){
    //     cout << dx[i] << " ";
    // }cout << dx[dx.size()-1] << endl;
    // for(int i=0; i<dy.size()-1; i++){
    //     cout << dy[i] << " ";
    // }cout << dy[dy.size()-1] << endl;
    // cout << xini << endl;

    if(dp(dx,x,xini) && dp(dy,y,0)){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
