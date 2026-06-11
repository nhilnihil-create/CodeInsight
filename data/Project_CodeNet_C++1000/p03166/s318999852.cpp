#include<bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    #ifdef LOCAL_EXEC
    #else
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #endif // LOCAL_EXEC
    long long int i,j,k,x,y,z,n,m;
    cin>>n>>m;
    long long int dp[n+1]={0};
    stack<long long int>st;
    vector<long long int>vt[n+1];
    for(i=1;i<=m;i++){
        cin>>x>>y;
        vt[x].push_back(y);
    }
    long long int ans=0;
    bool visited[n+1]={false};
    for(i=1;i<=n;i++){
        if(visited[i]==true)
            continue;
        st.push(i);
        while(!st.empty()){
            x=st.top();
            visited[x]=true;
            for(j=0;j<vt[x].size();j++){
                if(visited[vt[x][j]]==false){
                    st.push(vt[x][j]);
                    break;
                }
                    dp[x]=max(dp[x],dp[vt[x][j]]+1);
            }
            if(j==vt[x].size())
                st.pop();
        }

    }
    for(i=1;i<=n;i++){
        ans=max(ans,dp[i]);
       // cout<<dp[i]<<endl;
    }
    cout<<ans;
    return 0;
}
