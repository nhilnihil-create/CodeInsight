#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200003,INF=1<<30;

int dp[MAX];

int main(){
    
    string S;cin>>S;
    int N=S.size();
    
    int bit=0;
    vector<int> data(N+1,0);
    map<int,vector<int>> MA;
    for(int i=0;i<N;i++){
        bit^=(1<<(S[i]-'a'));
        if(MA[bit].size()==2) MA[bit].pop_back();
        MA[bit].push_back(i+1);
        data[i+1]=bit;
    }
    for(int i=1;i<=N;i++) dp[i]=INF;
    dp[0]=0;
    
    for(int i=0;i<N;i++){
        if(dp[i]>=INF) continue;
        for(auto to:MA[data[i]]) dp[to]=min(dp[to],dp[i]+1);
        //if(i<MA[data[i]]) dp[MA[data[i]]]=min(dp[MA[data[i]]],dp[i]+1);
        
        for(int j=0;j<26;j++){
            data[i]^=(1<<j);
            //if(i==0) cout<<j<<" "<<data[i]<<endl;
            //if(i<MA[data[i]]) dp[MA[data[i]]]=min(dp[MA[data[i]]],dp[i]+1);
            for(auto to:MA[data[i]]) dp[to]=min(dp[to],dp[i]+1);
            data[i]^=(1<<j);
        }
    }
    
    cout<<dp[N]<<endl;
    
    //for(int i=0;i<=N;i++) cout<<i<<" "<<data[i]<<" "<<dp[i]<<endl;
    
}
