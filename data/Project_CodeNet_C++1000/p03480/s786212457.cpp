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

string S;
int main(){
    cin>>S;
    ll ans=INF;
    for(ll i=0;i<S.length();i++){
        if(S[i]!=S[i+1]){
            ans=min(ans,max(i+1,(ll)S.length()-(i+1)));
        }
    }
    cout<<ans<<endl;
    return 0;
}