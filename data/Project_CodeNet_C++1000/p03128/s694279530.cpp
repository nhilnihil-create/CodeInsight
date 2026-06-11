#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cstdio>
#include<cmath>
using namespace std;
//#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
int MOD=1000000007;
bool compare(string const& a,string const& b,int push){
    bool res=true;
    if(a=="inf"){
        res=false;
        goto FINE;
    }
    if(b=="inf")goto FINE;
    if((int)a.length()+1==b.length()){
        int n=(int)b.length();
        int i=0;
        while(a[i]==b[i]&&i<n)i++;
        if(a[i]<b[i]&&i<n)res=false;
        else if(i==n){
            if(push+'0'<b[i])res=false;
        }
    }
    else if((int)a.length()+1<(int)b.length())res=false;
    else res=true;
    FINE:
    return res;
}
signed main(){
    int n,m;cin>>n>>m;
    vector<int> num={0,2,5,5,4,5,6,3,7,6};
    vector<int> a(m);
    rep(i,m)cin>>a[i];
    vector<pair<int,int>> use;
    rep(i,m){
        use.push_back(make_pair(a[i],num[a[i]]));
    }
    sort(use.begin(),use.end());
    reverse(use.begin(),use.end());
    vector<string> dp(10001,"inf");
    dp[0]='0';
    rep(i,m){
        rep(j,n+1){
            if(j>=use[i].second){
                if(compare(dp[j-use[i].second],dp[j],use[i].first)){
                    dp[j]=dp[j-use[i].second];
                    dp[j]+=use[i].first+'0';
                }
            }
        }
    }
    rep(i,n+1){
        //cout<<dp[i]<<" ";
    }
    //cout<<endl;
    int numm=(int)dp[n].size();
    for(int i=1;i<numm;i++)cout<<dp[n][i];
    cout<<endl;
    //cout<<dp[n]<<endl;
    return 0;
}