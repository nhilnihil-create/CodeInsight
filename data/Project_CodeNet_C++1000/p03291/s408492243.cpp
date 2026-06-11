//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    string s; cin>>s;
    ll c=1,n=s.size();
    vector<vector<ll>> dp(n+1,vector<ll>(3,0));
    for(int i=1;i<=n;i++){
        rep(j,3) dp[i][j]=dp[i-1][j];
        if(s[i-1]=='A'){
            dp[i][0]+=c;
            dp[i][0]%=MOD;
        }
        else if(s[i-1]=='B'){
            dp[i][1]+=dp[i-1][0];
            dp[i][1]%=MOD;
        }
        else if(s[i-1]=='C'){
            dp[i][2]+=dp[i-1][1];
            dp[i][2]%=MOD;
        }
        else{
            dp[i][0]*=3;
            dp[i][0]+=c;
            dp[i][0]%=MOD;
            dp[i][1]*=3;
            dp[i][1]+=dp[i-1][0];
            dp[i][1]%=MOD;
            dp[i][2]*=3;
            dp[i][2]+=dp[i-1][1];
            dp[i][2]%=MOD;
            c=(c*3)%MOD;
        }
    }
    cout<<dp[n][2]<<endl;
}