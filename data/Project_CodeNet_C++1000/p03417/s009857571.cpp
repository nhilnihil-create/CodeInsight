#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

int main(void){
    ll n, m;
    cin>>n>>m;
    ll ans;
    if(n==1&&m==1) ans=1;
    else if(n==1) ans=m-2;
    else if(m==1) ans=n-2;
    else {
        ans=n*m;
        ans-=(n*2+m*2-4);
    }
    cout<<ans<<endl;
    return 0;
}
