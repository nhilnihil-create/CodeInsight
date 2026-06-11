#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int num;
int main()
{
    int a;
    int temp;
    vector<int> cost(1e5+1,0);
    vector<int> dp(1e5+1,0);
    while(cin>>a){
        fill(cost.begin(),cost.end(),0);
        fill(dp.begin(),dp.end(),0);
        for(int i=0;i<a;i++){
            cin>>cost[i];
        }
        temp=0;
        dp[0]=0;
        dp[1]=abs(cost[1]-cost[0]);
        for(int i=2;i<a;i++){
            dp[i]=min(dp[i-1]+abs(cost[i-1]-cost[i]),dp[i-2]+abs(cost[i-2]-cost[i]));
        }
        cout<<dp[a-1]<<endl;
    }
}
