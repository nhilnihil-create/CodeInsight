#include<bits/stdc++.h>
using namespace std;
const int nax=1e5+5;
vector<int> edge [nax];
int mod=1e9+7;
int mul(int a,int b)
{
    return (long long) a*b%mod;
}
pair<int,int> dfs(int a,int parent)
{
    int white=1;
    int black=0;
    for(auto x: edge[a])
    {
        if(x!=parent)
        {
            pair<int,int> p=dfs(x,a);
           int  old_white=white;
            white=mul(white,p.second);
            black=(mul(old_white,p.first)+mul(black,p.first+p.second))%mod;
        }
    }
    return make_pair(white,(white+black)%mod);
}
int  main()
{
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    pair<int,int> ans=dfs(1,-1);
    cout<<(ans.first+ans.second)%mod<<endl;
}