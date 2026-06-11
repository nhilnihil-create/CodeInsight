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

int main(){
    cin>>N>>K;
    if(K==0){
        cout<<N*N<<endl;
        return 0;
    }
    ll ans=0;
    for(ll b=K;b<=N;b++){
        ans+=N/b*(b-K);
        ans+=max(0ll,min(N,(N/b+1)*b-1)-(N/b*b+K)+1);
    }
    cout<<ans<<endl;
    return 0;
}