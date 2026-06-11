#include<bits/stdc++.h>
using namespace std;

#define int long long int 

int32_t main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> s(n,vector<int>(3,0));
    for(int i=0;i<n;i++)
    for(int j=0;j<3;j++)
    cin>>s[i][j];
    int ans=INT_MIN;
    for(int i=0;i<8;i++)
    {
        vector<int> v;
        for(int j=0;j<n;j++)
        {
            int x=0;
            for(int k=0;k<3;k++)
            {
                
                if(((i>>k)&1)==0)
                x+=s[j][k];
                else
                x-=s[j][k];
            }
            v.push_back(x);
            
        }
        sort(v.begin(),v.end());
        std::reverse(v.begin(),v.end());
        int p=0;
        for(int j=0;j<m;j++)
        p+=v[j];
        ans=max(ans,p);
    }
    cout<<ans<<endl;
}
    