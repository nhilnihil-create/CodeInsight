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
const ll ARG_MAX=1e6;

ll N;
ll a[ARG_MAX];
ll second1Place[30][ARG_MAX]={};
int main(){
    cin>>N;
    for(ll i=0;i<N;i++){
        cin>>a[i];
    }
    for(ll bit=0;bit<=20;bit++){
        bool nowBit=a[0]&(1<<bit);
        ll start=0;
        ll first1place=0;
        for(ll i=1;i<N;i++){
            if(a[i]&(1<<bit) ){
                if(nowBit){
                    for(ll j=start;j<=first1place;j++){
                        second1Place[bit][j]=i;
                    }
                    start=first1place+1;
                    first1place=i;
                }else{
                    nowBit=true;
                    first1place=i;
                }
            }
        }
    }
    ll ans=0;
    for(ll i=0;i<N;i++){
        ll minPlace=N;
        for(ll bit=0;bit<=20;bit++){
            if(second1Place[bit][i]==0)continue;
            minPlace=min(minPlace,second1Place[bit][i]);
        }
        ans+=(minPlace-i);
        
    }
    cout<<ans<<endl;
    return 0;
}