#include <iostream>
#include <vector>
using namespace std;

long long int getValue(vector<long long int>dp,int index){
    return dp[index]==0?1:dp[index];
}
int main()
{
    long long int  n;
    cin>>n;
    vector<long long int>dp(26,0);
    for(int i=0;i<n;i++)
    {
        string element;
        cin>>element;
        dp[element[0]-'A']++;
    }
    vector<long long int>result;
    result.push_back(dp[12]);
    result.push_back(dp[0]);
    result.push_back(dp[17]);
    result.push_back(dp[2]);
    result.push_back(dp[7]);
    long long int finalresult=0;
    for(int i=0;i<5;i++)
    {
        long long int temp=1;
        for(int j=i+1;j<5;j++)
        {
            for(int k=j+1;k<5;k++)
            {   
                temp=result[i]*result[j]*result[k];
                finalresult+=temp;
            }
            
        }
    }
    cout<<finalresult;
}