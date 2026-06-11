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
const ll INF=2e18;
const ll MOD=2e18;
const double EPS=1e-7;

ll N;
string c[500];
int main(){
    cin>>N;
    for(ll i=0;i<N;i++){
        cin>>c[i];
    }
    ll ans=0;
    for(ll a=0;a<N;a++){
        for(ll i=0;i<N;i++){
            char tmp=c[i][0];
            for(ll j=0;j<N-1;j++){
                c[i][j]=c[i][j+1];
            }
            c[i][N-1]=tmp;
            //cout<<c[i]<<endl;
        }
        bool isSame=true;
        for(ll i=0;i<N;i++){
            string tmp1,tmp2;
            tmp1=c[i].substr(i+1,N-(i+1));
            for(ll j=i+1;j<N;j++){
                tmp2+=c[j][i];
            }
            if(tmp1!=tmp2){
                isSame=false;
                break;
            }
        }
        if(isSame){
            ans+=N;
        }
    }
    cout<<ans<<endl;

    
}