#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int max_count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int count=0;
            vector<bool>dp(26,false);
            for(int k=0;k<=j;k++)
            {
                dp[s[k]-'a']=true;
            }
            for(int k=j+1;k<n;k++)
            {
                if(dp[s[k]-'a']==true){
                    dp[s[k]-'a']=false;
                    count++;
                }
            }
            if(max_count<count){
                max_count=count;
            }
        }
    }
    cout<<max_count;
}