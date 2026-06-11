#include<bits/stdc++.h>
using namespace std;
template <typename T> void max_self(T& a,T b){
    a=max(a,b);
}

int main()
{
    string s,t;
    cin>>s>>t;
    int len1=s.length(),len2=t.length();
    vector<vector<pair<int,pair<int,int>>>> dp(len1+1,vector<pair<int,pair<int,int>>>(len2+1,{0,{0,0}}));
    for(int i=1;i<=len1;i++){
        for(int j=1;j<=len2;j++){
            if(s[i-1]==t[j-1]) max_self(dp[i][j],{dp[i-1][j-1].first+1,{i-1,j-1}});
            else{
               max_self(dp[i][j],{dp[i-1][j].first,{i-1,j}});
               max_self(dp[i][j],{dp[i][j-1].first,{i,j-1}});
            }
        }
    }
     string ans="";
     //cout<<"hello"<<"\n";
    pair<int,pair<int,int>> answer={0,{0,0}};
    for(int i=0;i<=len1;i++){
        for(int j=0;j<=len2;j++){
            max_self(answer,{dp[i][j].first,{i,j}});
        }
    }
    //cout<<"hi"<<"\n";
    pair<int,int> cur=answer.second;
     while(cur.first>0 && cur.second>0){
        int i=cur.first;
        int j=cur.second;
       // cout<<"i ="<<i<<"j="<<j<<"\n";
        pair<int,int> prev=dp[i][j].second;
        if(prev==make_pair(i-1,j-1)){
           ans+=s[i-1];
        }
        cur=prev;
     }
    reverse(ans.begin(),ans.end());
    cout<<ans;
}
