#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<list>
#include<climits>
using namespace std;

int dp[100001];


int lg(vector<list<int>>& v,int n, int m,int src){

    if(dp[src]!=-1)
        return dp[src];
    
    int leaf=1;
    int bestChild = 0;
    for(auto child : v[src]){
        leaf = 0;
        bestChild = max(bestChild,1+lg(v,n,m,child));
    }
    
    return dp[src] = leaf ? 0 : bestChild;
}

int main(){

    int n,m;
    cin>>n>>m;
    vector<list<int>> v(n+1);

    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
    }
    memset(dp,-1,sizeof(dp));

    // for(int i=1;i<=n;i++){
    //     cout<<i<<" : ";
    //     for(auto element:v[i]){
    //         cout<<element<<",";
    //     }
    //     cout<<endl;
    // }
    int ans = 0;
    for(int i=1;i<=n;i++){
        ans=max(ans,lg(v,n,m,i));
    }
    cout<<ans<<endl;
    return 0;
}