#include <iostream>
#include <deque>
#include <vector>
#include <cmath>
#define inf 99999999
using namespace std;
int a,b;
int max1;
deque<int> ha[100010];
deque<int> dp(100010);
deque<int> vis(100010);
int cal(int idx){
    if(vis[idx]) return dp[idx];
    while(!ha[idx].empty()){
        int a=ha[idx].front();
        ha[idx].pop_front();
        dp[idx]=max(dp[idx],1+cal(a));
    }
    vis[idx]=true;
    return dp[idx];
}
int main()
{
    int temp1;
    int temp2;
    while(cin>>a>>b){
        fill(dp.begin(),dp.end(),0);
        fill(vis.begin(),vis.end(),false);
        for(int i=1;i<=b;i++){
            cin>>temp1>>temp2;
            ha[temp1].push_back(temp2);
        }
        for(int i=1;i<a+1;i++){
            cal(i);
        }
        int max1=0;
        for(int i=0;i<dp.size();i++){
            if(dp[i]>max1){
                max1=dp[i];
            }
        }
        cout<<max1<<endl;
    }
}
