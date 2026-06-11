#include <bits/stdc++.h>
#define REP(i,n) for(LL i=0;i<(LL)(n);i++)
#define ALL(x) (x).begin(),(x).end()
#define LL long long
#define pii pair<LL,LL>
#define pll pair<LL,LL>

using namespace std;

int main(){

    string s;cin>>s;
    LL n=s.size();
    LL isOdd[n+1];
    fill_n(isOdd,n+1,0);

    LL dp[n+1];
    fill_n(dp,n+1,1000000);
    dp[0]=0;

    map<LL,LL> bLLoid;
    LL vec[n+1];
    fill_n(vec,n+1,-1);
    vec[0]=0;
    bLLoid[0]=0;

    LL nid = 1;

    REP(i,n){
        LL c = s[i]-'a';
        isOdd[i+1]=(isOdd[i]^(1<<c));
        REP(j,26){
            LL k = isOdd[i+1]^(1<<j);
            if(bLLoid.find(k)==bLLoid.end()){
                dp[i+1]=min(dp[i+1],dp[i]+1);
                continue;
            }
            LL id = bLLoid[k];
            //for(LL v : vec[id])dp[i+1]=min(dp[i+1],dp[v]+1);
            dp[i+1]=min(dp[i+1],dp[vec[id]]+1);
        }
        if(bLLoid.find(isOdd[i+1])!=bLLoid.end()){
            LL id = bLLoid[isOdd[i+1]];
            if(dp[i+1]<dp[vec[id]]+1){
                vec[id]=i+1;
            }else{
                dp[i+1]=dp[vec[id]]+1;
            }
        }

        if(bLLoid.find(isOdd[i+1])==bLLoid.end()){
            bLLoid[isOdd[i+1]]=nid++;
        }
        if(vec[bLLoid[isOdd[i+1]]]<0)vec[bLLoid[isOdd[i+1]]]=(i+1);

    }

    cout<<dp[n]<<endl;
    return 0;
}