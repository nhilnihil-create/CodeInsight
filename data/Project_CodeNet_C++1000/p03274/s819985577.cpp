#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;

int main(){
    ll n,k;
    cin>>n>>k;
    k--;
    vector<ll> x(n);
    for(int i=0;i<n;i++){
        cin>>x[i];
    }

    ll ans=1000000000;
    for(int i=0;i<n-k;i++){
        ll dif=min(abs(x[i+k]),abs(x[i]))+abs(x[i+k]-x[i]);
        if(ans>dif){
            ans=dif;
        }
    }
    cout<<ans<<endl;
    return 0;
}