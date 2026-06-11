#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<math.h>
using namespace std;
#define N (1000000000+7)
#define INF 1e16
typedef long long ll;
typedef pair<ll,ll> P;

ll dp[200010];
ll mostright[200010];

int main(void){
    ll n;
    cin>>n;
    vector<ll>in(n),c;
    for(ll i=0;i<n;i++){
        cin>>in[i];
    }
    for(ll i=0;i<n;){
        ll j=i;
        while(true){
            if(i==n)break;
            if(in[j]==in[i])i++;
            else break;
        }
        c.push_back(in[j]);
    }
    for(ll i=0;i<200010;i++)mostright[i]=-1;
    dp[0]=0;
    dp[1]=1;
    mostright[c[0]]=1;
    for(ll i=1;i<(ll)c.size();i++){
        dp[i+1]=dp[i];
        if(mostright[c[i]]!=-1)dp[i+1]=(dp[i+1]+dp[mostright[c[i]]])%N;
        mostright[c[i]]=i+1;
        //cout<<i+1<<" "<<dp[i+1]<<endl;
    } 
    cout<<dp[(ll)c.size()]<<endl;
    return 0;
}
