#include <iostream>
#include <vector>
using namespace std;
int main(){
    int a;
    while(cin>>a){
        vector<vector<int>> dp(a,vector<int> (3,0));
        vector<vector<int>> num(a,vector<int> (3,0));
        for(int i=0;i<a;i++){
            for(int j=0;j<3;j++){
                cin>>num[i][j];
            }
        }
        dp[0][0]=num[0][0];
        dp[0][1]=num[0][1];
        dp[0][2]=num[0][2];
        for(int i=1;i<a;i++){
            for(int j=0;j<3;j++){
                if(j==0){
                    dp[i][j]=max(dp[i-1][1]+num[i][0],dp[i-1][2]+num[i][0]);
                }
                else if(j==1){
                    dp[i][j]=max(dp[i-1][0]+num[i][1],dp[i-1][2]+num[i][1]);
                }
                else if(j==2){
                    dp[i][j]=max(dp[i-1][0]+num[i][2],dp[i-1][1]+num[i][2]);
                }
            }
        }
        int t=max(dp[a-1][0],dp[a-1][1]);
        cout<<max(t,dp[a-1][2])<<endl;
    }
}
