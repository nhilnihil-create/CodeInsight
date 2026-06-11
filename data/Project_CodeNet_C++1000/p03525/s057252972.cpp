#include<iostream>
#include<math.h>
#include<algorithm>
#include<utility>
#include<queue>
#include<string.h>
#include<string>
#include<set>
#include<map>
#include<unordered_map>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=2e18;
const ll MOD=1e9+7;

ll N,M,K;
ll d[100010];
int main(){
    cin>>N;
    for(ll i=0;i<N;i++){
        cin>>d[i];
    }
    sort(d,d+N);
    for(ll i=0;i<N;i++){
        if(i%2==1 && d[i]!=0){
            d[i]=24-d[i];
        }
    }
    sort(d,d+N);
    ll ans=d[0];
    for(ll i=1;i<N;i++){
        ans=min(ans,d[i]-d[i-1]);
    }
    cout<<ans<<endl;
    return 0;
}