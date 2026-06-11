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

ll A,B;
char c[101][101];
int main(){
    cin>>A>>B;
    for(ll i=0;i<50;i++){
        for(ll j=0;j<100;j++){
            c[i][j]='.';
        }
    }
    for(ll i=50;i<100;i++){
        for(ll j=0;j<100;j++){
            c[i][j]='#';
        }
    }
    P now=P(1,1);
    for(ll i=0;i<B-1;i++){
        c[now.first][now.second]='#';
        now.second+=2;
        if(now.second>100){
            now.first+=2;
            now.second=1;
        }
    }
    now=P(51,1);
    for(ll i=0;i<A-1;i++){
        c[now.first][now.second]='.';
        now.second+=2;
        if(now.second>100){
            now.first+=2;
            now.second=1;
        }
    }
    cout<<"100 100"<<endl;
    for(ll i=0;i<100;i++){
        for(ll j=0;j<100;j++){
            cout<<c[i][j];
        }cout<<endl;
    }
    return 0;
}