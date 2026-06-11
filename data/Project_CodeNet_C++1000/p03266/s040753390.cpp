#define _LIBCPP_DEBUG 0
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll MOD = 1e9 + 7;

int main(void){

    ll N,K; cin>>N>>K;
    ll ans = 0;
    ans = (N/K) * (N/K) * (N/K);
    ll tmp = (N/(K/2))-(N/K);
    if(K%2==0) ans += tmp*tmp*tmp;

    cout<<ans<<endl;

}