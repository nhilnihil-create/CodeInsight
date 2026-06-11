#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=5005;
const ll INF=1LL<<60;
ll dp[MAX][MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    ll A,B;cin>>A>>B;
    vector<int> S(N);
    for(int i=0;i<N;i++) cin>>S[i];
    
    for(int i=0;i<=N;i++){
        for(int j=0;j<=N;j++){
            dp[i][j]=INF;
        }
    }
    dp[0][0]=0;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<=N;j++){
            if(j<S[i]){
                dp[i+1][S[i]]=min(dp[i+1][S[i]],dp[i][j]);
                dp[i+1][j]=min(dp[i+1][j],dp[i][j]+A);
            }else{
                dp[i+1][j]=min(dp[i+1][j],dp[i][j]+B);
            }
        }
    }
    
    ll ans=INF;
    
    for(int i=1;i<=N;i++) ans=min(ans,dp[N][i]);
    
    cout<<ans<<endl;
}
