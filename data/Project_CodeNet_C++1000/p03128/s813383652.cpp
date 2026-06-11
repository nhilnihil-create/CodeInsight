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

ll N,M;
ll a[10];
const ll matchNum[10]={0,2,5,5,4,5,6,3,7,6};
string dp[10010];
bool valid[100010]={};
int main(){
    cin>>N>>M;
    for(ll i=0;i<M;i++){
      cin>>a[i];
    }
    valid[0]=true;
    for(ll i=0;i<N;i++){
      if(!valid[i])continue;
      for(ll j=0;j<M;j++){
        ll plusMatchNum=matchNum[a[j]];
        ll nextI=i+plusMatchNum;
        if(nextI > N )continue;
        string tmp;
        tmp+=a[j]+'0';
        tmp+=dp[i];
        if( (dp[nextI].length() < tmp.length()) || 
            (dp[nextI].length()== tmp.length() && dp[nextI]<tmp)){
            dp[nextI]=tmp;
            valid[nextI]=true;
        }
      }
    }
    cout<<dp[N]<<endl;
    return 0;
}