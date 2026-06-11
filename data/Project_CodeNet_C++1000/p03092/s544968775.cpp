#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
    int n,x,y;
    cin>>n>>x>>y;
    int b[n+1];
    rep(i,n)cin>>b[i];
    b[n]=n+1;
    vector<ll> dp(n+2,longinf);
    dp[0]=0;
    rep(i,n+1){
        ll sum=0;
        for(int j = i-1;j>=0;--j){
            if(b[j]>b[i])sum+=x;
            if(b[j]<b[i]){
                dp[i+1]=min(dp[i+1],dp[j+1]+sum);
                sum+=y;
            }
        }
        dp[i+1]=min(dp[i+1],sum);
    }
    cout<<dp[n+1]<<endl;
    return 0;
}