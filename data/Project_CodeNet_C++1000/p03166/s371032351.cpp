/*THERE'S ALWAYS SOMETHING , NOT THAT YOU WOULD UNDERSTAND . YOU ARE LIKE MY SISTER ,
 EVERYTHING ALWAYS CAME EASY TO HER .
 SHE'S A FIRE BENDING PRODIGY AND EVERY ONE ADORE HER . MY FATHER SAYS
 SHE WAS BORN LUCKY ,HE SAYS I WAS LUCKY TO BE BORN . I DON'T NEED LUCK THOUGH .
 I DON'T WANT IT . I'VE ALWAYS HAD TO STRUGGLE AND FIGHT
 AND THAT'S MADE ME STRONG . IT MADE ME WHO I AM .*/
#include<bits/stdc++.h>
using namespace std;
vector<int> graph[100001];
int dp[100001];  //dp[i] = length of longest path starting at i;
int solve(int src)
{
    if(dp[src]!=-1)return dp[src];
    bool leaf =1;
    int bestchild=0;
    for(int child:graph[src])
    {
        leaf=0;
        bestchild=max(bestchild,solve(child));
    }
    return dp[src]=leaf?0:1+bestchild;
}
main()
{
    int n,m;
    cin>>n>>m;
    memset(dp,-1,sizeof dp);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
    }
    int ans=0;
    for(int i=1;i<=n;i++)ans=max(solve(i),ans);

    cout<<ans;
}






















































































































/* WHATEVER DOESNT KILL ME ONLY MAKES ME STRONGER .*/
