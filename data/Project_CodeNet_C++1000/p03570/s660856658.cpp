#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

const int INF=1001001001001001001ll;

int N;
string S;

int b[222222];

signed main(){
    cin>>S;
    N=S.size();
    rep(i,N){
        b[i+1]=b[i]^(1<<(S[i]-'a'));
    }

    map<int,int>dp;
    dp[0]=0;
    rep(i,N-1){
        int hoge=INF;
        rep(j,26){
            int tmp=b[i+1]^(1<<j);
            if(dp.find(tmp)!=dp.end()){
                chmin(hoge,dp[tmp]+1);
            }
        }

        if(dp.find(b[i+1])!=dp.end())chmin(dp[b[i+1]],hoge);
        else dp[b[i+1]]=hoge;
    }

    int ans=INF;

    rep(i,26){
        int tmp=b[N]^(1<<i);
        if(dp.find(tmp)!=dp.end())chmin(ans,dp[tmp]+1);
    }
    if(b[N]==0)ans=1;
    cout<<ans<<endl;
    return 0;
}
