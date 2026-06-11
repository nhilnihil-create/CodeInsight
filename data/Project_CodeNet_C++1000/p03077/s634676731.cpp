#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>
#include<tuple>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<bitset>
#include<math.h>
using namespace std;
using ll = int64_t;
using Graph = vector<vector<int> >;
const ll M = 1000000007;

ll ce(ll x,ll y){
    return (y+(x-1))/x;
}

int main(){
    ll n,a,b,c,d,e;
    cin >> n >> a >> b >> c >> d >> e;

    ll tmp[5];
    tmp[0]=ce(a,n);
    tmp[1]=ce(b,n);
    tmp[2]=ce(c,n);
    tmp[3]=ce(d,n);
    tmp[4]=ce(e,n);

    ll ans=tmp[0];
    ll mx=tmp[0];
    for(int i=1;i<5;i++){
        if(mx>=tmp[i]) {
            ans++;
        }else{
            ans=tmp[i]+i;
            mx=tmp[i];
        }
    }

    cout << ans << endl;    
}