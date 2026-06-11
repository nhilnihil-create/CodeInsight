#include <iostream>
#include <vector>
#include <cmath>
#define inf 999999999
using namespace std;
int num;
int main()
{
    int a,b;
    int temp;
    vector<int> cost(1e5+1);
    vector<int> dp(1e5+1);
    while(cin>>a>>b){
        fill(cost.begin(),cost.end(),0);
        fill(dp.begin(),dp.end(),inf);
        for(int i=0;i<a;i++){
            cin>>cost[i];
        }
        dp[0]=0;
        dp[1]=abs(cost[1]-cost[0]);
        for(int i=1;i<a;i++){
            for(int j=1;j<=i && j<=b;j++){
                 dp[i]=min(dp[i],dp[i-j]+abs(cost[i-j]-cost[i]));
            }
        }
        cout<<dp[a-1]<<endl;
    }
}
