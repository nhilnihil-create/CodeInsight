#include<bits/stdc++.h>
#define REP(i,n) for(int i=0,i##_len=(n);i<i##_len;++i)
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define All(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;

int main(){
    int N;cin>>N;
    string s;cin>>s;
    int Q;cin>>Q;
    vector<ll[2]> dp(N+1);
    vector<ll> c(N+1);
    REP(i,N){
        dp[i+1][0]=dp[i][0];
        dp[i+1][1]=dp[i][1];
        c[i+1]=c[i];
        if(s[i]=='M') dp[i+1][0]++;
        if(s[i]=='C'){
            dp[i+1][1]+=dp[i][0];
            c[i+1]++;
        }
    }
    REP(_,Q){
        int k;cin>>k;
        ll ans=0;
        REP(i,N) if(s[i]=='D'){
            int r=min(i+k,N);
            ans+=dp[r][1]-dp[i][1]-dp[i][0]*(c[r]-c[i]);
        }
        cout<<ans<<endl;
    }
}
