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

ll H,W,N;
ll sh,sw;
string S,T;
int main(){
    cin>>H>>W>>N;
    cin>>sh>>sw;
    cin>>S>>T;

    ll narrowed[4]={};
    string plusC= "LRUD";
    string minusC="RLDU";
    ll limit[4]={W,W,H,H};
    ll start[4]={sw,sw,sh,sh};

    for(ll i=0;i<4;i++){
        for(ll j=N-1;j>=0;j--){
            if( T[j]==minusC[i] && narrowed[i]>0 ) narrowed[i]--;
            if( S[j]==plusC[i] ) narrowed[i]++;
            if( narrowed[i]>=limit[i] ){
                cout<<"NO";
                return 0;
            }
        }
    }
    if(sw<narrowed[0]+1 || W-narrowed[1]<sw || sh<narrowed[2]+1 || H-narrowed[3]<sh){
        cout<<"NO";
        return 0;
    }
    cout<<"YES";
    return 0;
}