#include<iostream>
#include<iomanip>
#include<math.h>
#include<algorithm>
#include<utility>
#include<queue>
#include<string.h>
#include<string>
#include<set>
#include<map>
#include<unordered_map>
#include<functional>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=2e18;
const ll MOD=1e9+7;

ll N,K;
ll a[100010];
ll dp[50][2]={};
int main(){
    cin>>N>>K;
    for(ll i=0;i<N;i++){
        cin>>a[i];
    }
    for(ll i=0;i<=41;i++){
        for(ll j=0;j<2;j++){
            dp[i][j]=-INF;
        }
    }
    dp[41][0]=0;
    for(ll i=40;i>=0;i--){
        ll trueCnt=0;
        for(ll j=0;j<N;j++){
            if((1ll<<i)&a[j]){
                trueCnt++;
            }
        }
        for(ll j=0;j<2;j++){
            for(ll bit=0;bit<=1;bit++){
                ll nextj=j;
                if(j==0){
                    if(bit && !((1ll<<i)&K))continue;
                    if(!bit && ((1ll<<i)&K)){
                        nextj=1;
                    }
                }
                dp[i][nextj]=max(dp[i][nextj],dp[i+1][j]+(1ll<<i)*((bit)?(N-trueCnt):trueCnt));
            }
        }        
    }
    cout<<max(dp[0][0],dp[0][1])<<endl;
    return 0;
}