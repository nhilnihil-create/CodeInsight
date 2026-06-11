#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
#define eb emplace_back
using ll=long long;
using P = pair<ll,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
const ll MOD=1000000007,MOD2=998244353;



int main() {
    string S;
    cin>>S;
    int L=sz(S);
    vector<vector<ll>> dp(4,vector<ll>(L+3));
    dp.at(0).at(0)=1;
    rep(i,L){
        if(S.at(i)=='A' || S.at(i)=='?'){
            dp.at(0).at(i+1)+=dp.at(0).at(i);
            dp.at(1).at(i+1)+=dp.at(0).at(i);
            dp.at(1).at(i+1)+=dp.at(1).at(i);
            dp.at(2).at(i+1)+=dp.at(2).at(i);
            dp.at(3).at(i+1)+=dp.at(3).at(i);
            dp.at(0).at(i+1)%=MOD;
            dp.at(1).at(i+1)%=MOD;
            dp.at(2).at(i+1)%=MOD;
            dp.at(3).at(i+1)%=MOD;
        }
        if(S.at(i)=='B' || S.at(i)=='?'){
            dp.at(0).at(i+1)+=dp.at(0).at(i);
            dp.at(1).at(i+1)+=dp.at(1).at(i);
            dp.at(2).at(i+1)+=dp.at(1).at(i);
            dp.at(2).at(i+1)+=dp.at(2).at(i);
            dp.at(3).at(i+1)+=dp.at(3).at(i);
            dp.at(0).at(i+1)%=MOD;
            dp.at(1).at(i+1)%=MOD;
            dp.at(2).at(i+1)%=MOD;
            dp.at(3).at(i+1)%=MOD;
        }
        if(S.at(i)=='C' || S.at(i)=='?'){
            dp.at(0).at(i+1)+=dp.at(0).at(i);
            dp.at(1).at(i+1)+=dp.at(1).at(i);
            dp.at(2).at(i+1)+=dp.at(2).at(i);
            dp.at(3).at(i+1)+=dp.at(2).at(i);
            dp.at(3).at(i+1)+=dp.at(3).at(i);
            dp.at(0).at(i+1)%=MOD;
            dp.at(1).at(i+1)%=MOD;
            dp.at(2).at(i+1)%=MOD;
            dp.at(3).at(i+1)%=MOD;
        }
    }
    cout<<dp.at(3).at(L)<<endl;
}