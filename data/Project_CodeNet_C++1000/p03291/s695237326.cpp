#include<bits/stdc++.h>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll inf=1e9+7;
ll dp[100010][3];
int main(){
    string s;cin>>s;
    ll counter=1;
    if(s[0]=='A')dp[0][0]++;
    if(s[0]=='?'){
        dp[0][0]++;
        counter*=3%inf;
    }
    REP(i,1,s.size()){
        if(s[i]=='A'){
            dp[i][0]=(dp[i][0]+dp[i-1][0]+counter)%inf;
            dp[i][1]=(dp[i][1]+dp[i-1][1])%inf;
            dp[i][2]=(dp[i][2]+dp[i-1][2])%inf;
        }
        if(s[i]=='B'){
            dp[i][0]=(dp[i][0]+dp[i-1][0])%inf;
            dp[i][1]=(dp[i][1]+dp[i-1][0]+dp[i-1][1])%inf;
            dp[i][2]=(dp[i][2]+dp[i-1][2])%inf;
        }
        if(s[i]=='C'){
            dp[i][0]=(dp[i][0]+dp[i-1][0])%inf;
            dp[i][1]=(dp[i][1]+dp[i-1][1])%inf;
            dp[i][2]=(dp[i][2]+dp[i-1][1]+dp[i-1][2])%inf;
        }
        if(s[i]=='?'){
            dp[i][0]=(dp[i][0]+dp[i-1][0]+counter)%inf;
            dp[i][1]=(dp[i][1]+dp[i-1][1])%inf;
            dp[i][2]=(dp[i][2]+dp[i-1][2])%inf;
            dp[i][0]=(dp[i][0]+dp[i-1][0])%inf;
            dp[i][1]=(dp[i][1]+dp[i-1][0]+dp[i-1][1])%inf;
            dp[i][2]=(dp[i][2]+dp[i-1][2])%inf;
            dp[i][0]=(dp[i][0]+dp[i-1][0])%inf;
            dp[i][1]=(dp[i][1]+dp[i-1][1])%inf;
            dp[i][2]=(dp[i][2]+dp[i-1][1]+dp[i-1][2])%inf;
            counter=(counter*3)%inf;
        }
    }
    cout<<dp[s.size()-1][2]<<endl;
}