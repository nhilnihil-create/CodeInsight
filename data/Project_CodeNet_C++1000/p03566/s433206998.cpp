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

ll N;
double dp[101][401][201]={};
ll t[101];
ll v[101];
int main(){
    cin>>N;
    for(ll i=0;i<N;i++){
        cin>>t[i];
    }
    for(ll i=0;i<N;i++){
        cin>>v[i];
    }
    for(ll i=0;i<N;i++){
        for(ll j=0;j<t[i]*2;j++){
            for(ll k=0;k<=v[i]*2;k++){
                dp[i][j][k]=-INF;
            }
        }
    }
    dp[0][0][0]=0;
    for(ll i=0;i<N;i++){
        for(ll j=0;j<t[i]*2;j++){
            for(ll k=0;k<=v[i]*2;k++){
                ll nextI=i;
                ll nextJ=j+1;
                if(nextJ==t[i]*2){
                    nextI=i+1;
                    nextJ=0;
                }
                double now=dp[i][j][k];
                if( k!=v[i]*2 ){
                    dp[nextI][nextJ][k+1]=max(dp[nextI][nextJ][k+1],now+k/2.0/2.0+0.25);
                }
                dp[nextI][nextJ][k  ]=max(dp[nextI][nextJ][k  ],now+k/2.0/2.0);
                if(k-1<0)continue;
                dp[nextI][nextJ][k-1]=max(dp[nextI][nextJ][k-1],now+k/2.0/2.0-0.25);
            }
        }
    }
    cout<<setprecision(10)<<dp[N][0][0]<<endl;
    return 0;
}