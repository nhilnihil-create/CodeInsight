#include<bits/stdc++.h>
#define int long long
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

struct block
{
    int w,s,v;
    bool operator<(block& rhs){
        return w+s<rhs.w+rhs.s;
    }
};

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N; cin>>N;
    vector<block> blocks(N);
    for(int i=0;i<N;i++){
        int w,s,v; cin>>w>>s>>v;
        blocks[i]={w,s,v};
    }
    sort(blocks.rbegin(),blocks.rend());
    vector<int> w(N),s(N),v(N);
    for(int i=0;i<N;i++){
        w[i]=blocks[i].w;
        s[i]=blocks[i].s;
        v[i]=blocks[i].v;
    }

    const int maxS=*max_element(s.begin(),s.end());
    vector<vector<int>> dp(N+1,vector<int>(maxS+1,-1));
    for(int i=0;i<N;i++){
        chmax(dp[i+1][s[i]],v[i]);
        for(int j=0;j<=maxS;j++) if(dp[i][j]!=-1){
            chmax(dp[i+1][j],dp[i][j]);
            if(j>=w[i]){
                chmax(dp[i+1][min(j-w[i],s[i])],dp[i][j]+v[i]);
            }
        }
    }
    /*
    for(int i=0;i<=N;i++){
        for(int j=0;j<=maxS;j++) cout<<dp[i][j]<<' '; cout<<endl;
    }
    */
    cout<<*max_element(dp[N].begin(),dp[N].end())<<endl;
    return 0;
}