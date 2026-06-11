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

    map<LL,LL> btoi;
    btoi[0]=0;

    REP(i,n){
        LL c = s[i]-'a';
        isOdd[i+1]=(isOdd[i]^(1<<c));
        REP(j,26){
            LL k = isOdd[i+1]^(1<<j);
            if(btoi.find(k)==btoi.end())continue;
            dp[i+1]=min(dp[i+1],dp[btoi[k]]+1);
        }
        if(btoi.find(isOdd[i+1])!=btoi.end()){
            if(dp[i+1]<dp[btoi[isOdd[i+1]]]+1){
                btoi[isOdd[i+1]]=i+1;
            }else{
                dp[i+1]=dp[btoi[isOdd[i+1]]]+1;
            }
        }else{
            btoi[isOdd[i+1]]=i+1;
        }
    }

    cout<<dp[n]<<endl;
    return 0;
}