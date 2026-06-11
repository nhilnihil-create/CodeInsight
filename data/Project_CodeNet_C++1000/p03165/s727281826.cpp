    #include<bits/stdc++.h>
    using namespace std;
    int main(){
        string s1,s2;
        cin>>s1>>s2;
        vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1));
        for(int i=0;i<dp.size();i++)
        {
            dp[i][0]=0;
        }
        for(int i=0;i<dp[0].size();i++)
        {
            dp[0][i]=0;
        }
        for(int i=1;i<dp.size();i++)
        {
            for(int j=1;j<dp[i].size();j++)
            {
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        stack<char>st;
        int indexx=s1.size(),indexy=s2.size();
        while(indexx!=0&&indexy!=0){
            if(dp[indexx-1][indexy]==dp[indexx][indexy]){
                indexx--;
            }
            else
            if(dp[indexx][indexy-1]==dp[indexx][indexy]){
                indexy--;
            }
            else{
                st.push(s1[indexx-1]);
                indexx--;
                indexy--;
            }
        }
        while(!st.empty()){
            cout<<st.top();
            st.pop();
        }
    }