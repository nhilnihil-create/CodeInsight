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
#include<vector>
#include<functional>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=4e18;
const ll MOD=998244353;
const double EPS=1e-7;

ll N;
ll a[100];
int main(){
    cin>>N;
    ll maAbs=0;
    ll maAbsIndex=0;
    for(ll i=0;i<N;i++){
        cin>>a[i];
        if(maAbs <= abs(a[i])){
            maAbs=abs(a[i]);
            maAbsIndex=i;
        }
    }
    vector<P> ans;
    for(ll i=0;i<N;i++){
        a[i]+=a[maAbsIndex];
        ans.push_back(P(maAbsIndex+1 , i+1) );
    }
    if(a[0] > 0){//全部正
        for(ll i=1;i<N;i++){
            if(a[i-1]>a[i]){
                a[i]+=a[i-1];
                ans.push_back(P(i-1 +1 , i +1) );
            }
        }
    }else{
        for(ll i=N-1;i>=1;i--){
            if(a[i-1]>a[i]){
                a[i-1]+=a[i];
                ans.push_back(P(i +1,i-1 +1));
            }
        }
    }
    cout<<ans.size()<<endl;
    for(auto p:ans){
        cout<<p.first<<" "<<p.second<<endl;
    }
    return 0;
}