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
ll p[200010];
bool validPreInLeft[200010]={};
bool valid[200010]={};
int main(){
    cin>>N;
    for(ll i=0;i<N;i++){
        cin>>p[i];
    }
    for(ll i=0;i<N;i++){
        if(valid[p[i]-1]){
            validPreInLeft[p[i]]=true;
        }
        valid[p[i]]=true;
    }
    ll maxLen=1;
    ll nowLen=1;
    for(ll i=N;i>=1;i--){
        if(validPreInLeft[i]){
            nowLen++;
        }else{
            maxLen=max(maxLen,nowLen);
            nowLen=1;
        }
    }
    cout<<N-maxLen;
    return 0;
}