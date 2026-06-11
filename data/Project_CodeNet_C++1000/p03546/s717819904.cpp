#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vin=vector<int>;
using vll=vector<long long>;
using vvin=vector<vector<int>>;
using vvll=vector<vector<long long>>;
using vstr=vector<string>;
using vvstr=vector<vector<string>>;
using vch=vector<char>;
using vvch=vector<vector<char>>;
using vbo=vector<bool>;
using vvbo=vector<vector<bool>>;
using vpii=vector<pair<int,int>>;
using pqsin=priority_queue<int,vector<int>,greater<int>>;
#define mp make_pair
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define rep2(i,s,n) for(ll i=(s);i<(ll)(n);i++)
#define all(v) v.begin(),v.end()
#define decp(n) cout<<fixed<<setprecision((int)n)
const int inf=1e9+7;
const ll INF=1e18;



int main(){
    int h,w;cin>>h>>w;
    vvin dp(10,vin(10));
    rep(i,10)rep(j,10){
        int c;cin>>c;
        dp[i][j]=c;
    }
    rep(k,10)rep(i,10)rep(j,10)dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
    int sum=0;
    rep(i,h)rep(j,w){
        int a;cin>>a;
        if(a!=-1)sum+=dp[a][1];
    }
    cout<<sum<<endl;
}