#define _LIBCPP_DEBUG 0
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll MOD = 1e9 + 7;

int main(void){

    ll N,M; cin>>N>>M;
    ll ans = N*M;
    if(N==1 && M==1) cout<<ans<<endl;
    else if(N==1 || M==1) cout<<ans-2<<endl;
    else{
        cout<<(N-2)*(M-2)<<endl;
    }


}