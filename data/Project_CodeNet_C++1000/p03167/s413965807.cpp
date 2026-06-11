#include <bits/stdc++.h>
using namespace std;
int h,w;
vector <vector<char>> a;
vector <vector<long long>> dp;
const long long mod = pow(10,9)+7; 
int main(){
    cin >> h >> w;
    a = vector<vector<char>>(h,vector<char>(w));
    dp = vector<vector<long long>>(h,vector<long long>(w,0));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> a[i][j];
        }
    }
    dp[0][0]=1;
    for(int i = 1; i < h; i++){
        if(a[i][0]=='.'){
            if(a[i-1][0]=='.'){
                dp[i][0]=dp[i-1][0];
            }else{
                dp[i][0]=0;
            }
        }else{
            dp[i][0]=0;
        }
    }
    for(int i = 1; i < w; i++){
        if(a[0][i]=='.'){
            if(a[0][i-1]=='.'){
                dp[0][i]=dp[0][i-1];
            }else{
                dp[0][i]=0;
            }
        }else{
            dp[0][i]=0;
        }
    }

    for(int i = 1; i < h; i++){
        for(int j = 1; j < w; j++){
            if(a[i][j]=='#'){
                dp[i][j]=0;
            }else{
                long long tmp = 0;
                if(a[i-1][j]=='.')tmp+=dp[i-1][j];
                tmp%=mod;
                //if((i==1)&&(j==2))cout << tmp << endl;
                if(a[i][j-1]=='.')tmp+=dp[i][j-1];
                tmp%=mod;
                //if((i==1)&&(j==2))cout << tmp << endl;
                dp[i][j]=tmp;
            }
        }
    }
    cout << dp[h-1][w-1] << endl;
    #if 0
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    #endif
    return 0;
}