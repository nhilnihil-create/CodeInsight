#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=1<<30;
const int mod=1e9+7;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;cin >> s;
    int n=s.size();
    vector<vector<ll>> dp(n+1,vector<ll>(4));
    dp[0][0]=1;
    rep(i,n){
        rep(j,4){
            if(s[i]=='?'){
                (dp[i+1][j]+=dp[i][j]*3)%=mod;
            }
            else{
                (dp[i+1][j]+=dp[i][j])%=mod;
            }
        }
        if(s[i]=='A'){
            (dp[i+1][1]+=dp[i][0])%=mod;
        }
        else if(s[i]=='B'){
            (dp[i+1][2]+=dp[i][1])%=mod;
        }
        else if(s[i]=='C'){
            (dp[i+1][3]+=dp[i][2])%=mod;
        }
        else{
            rep(j,3){
                (dp[i+1][j+1]+=dp[i][j])%=mod;
            }
        }
    }
    cout << dp[n][3] << endl;
}