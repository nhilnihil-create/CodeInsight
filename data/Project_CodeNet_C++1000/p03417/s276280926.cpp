#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

int main(void){
    ll n, m;
    cin>>n>>m;
    ll big=max(n, m);
    ll small=min(n, m);
    n=big;
    m=small;
    ll ans;
    if(n==1) ans=1;
    else if(m==1) ans=n-2;
    else {
        ans=(n-2)*(m-2);
    }
    cout<<ans<<endl;
    return 0;
}