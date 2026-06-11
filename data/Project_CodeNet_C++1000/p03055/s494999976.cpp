#include<iostream>
#include<iomanip>
#include<cassert>
#include<math.h>
#include<complex>
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
vector<ll> edgeList[200010];
ll maxD=0,maxNode=-1;
ll Visit(ll n,ll p,ll d){
    ll ret=0;
    for(auto to:edgeList[n]){
        if(to!=p){
            ret=max(ret,Visit(to,n,d+1));
        }
    }
    if(ret==0 && maxD<d){
        maxD=d;
        maxNode=n;
    }
    return ret+1;
}
ll Diameter(){
    Visit(1,-1,0);
    return Visit(maxNode,-1,0)-1;
}
int main(){
    cin>>N;
    for(ll i=0;i<N-1;i++){
        ll a,b;
        cin>>a>>b;
        edgeList[a].push_back(b);
        edgeList[b].push_back(a);
    }
    if((Diameter()+1)%3==2){
        cout<<"Second";
        return 0;
    }
    cout<<"First";
    return 0;
}