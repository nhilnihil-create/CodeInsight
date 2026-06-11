#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000000
#define mod 1000000007
typedef long long ll;
const ll LINF = 1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll n,m;
vector<ll> a;

int main(){
    //考察
    /*
    Aの後ろにあるBCの数、Bの後ろにあるCの数
    結局DPじゃないか？
    Aもまだみてない、Aまでみた、Bまでみた
    の状態と
    i文字目まで見たっていう状態を持つDPな気がする
     */
    string s;
    cin>>s;
    ll n=s.size();
    ll dp[n+1][4]={};
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        if(s[i]=='?'){
            dp[i+1][0]=3*dp[i][0]%mod;
            dp[i+1][1]=3*dp[i][1]%mod;
            dp[i+1][2]=3*dp[i][2]%mod;
            dp[i+1][3]=3*dp[i][3]%mod;

        }
        else{
            dp[i+1][0]=dp[i][0];
            dp[i+1][1]=dp[i][1];
            dp[i+1][2]=dp[i][2];
            dp[i+1][3]=dp[i][3];
        }
        if(s[i]=='A'){
            dp[i+1][1]=(dp[i+1][1]+dp[i][0])%mod;
        }
        else if(s[i]=='B'){
            dp[i+1][2]=(dp[i+1][2]+dp[i][1])%mod;
        }
        else if(s[i]=='C'){
            dp[i+1][3]=(dp[i+1][3]+dp[i][2])%mod;
        }
        else{//?
            dp[i+1][1]=(dp[i+1][1]+dp[i][0])%mod;
            dp[i+1][2]=(dp[i+1][2]+dp[i][1])%mod;
            dp[i+1][3]=(dp[i+1][3]+dp[i][2])%mod;
        }
    }

    cout<<dp[n][3]<<endl;
    return 0;
}