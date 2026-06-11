#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()


int main(){
    ll a,b;
    cin>>a>>b;
    
    if(a==0 || a==1){
        ll ans;
        if(b%4==1) ans=1;
        else if(b%4==2) ans=b+1;
        else if(b%4==3) ans=0;
        else ans=b;
        cout<<ans<<endl;
        return 0; 
    }

    ll tmpb,tmpa;
    if(b%4==1) tmpb=1;
    else if(b%4==2) tmpb=b+1;
    else if(b%4==3) tmpb=0;
    else tmpb=b;

    if((a-1)%4==1) tmpa=1;
    else if((a-1)%4==2) tmpa=a;
    else if((a-1)%4==3) tmpa=0;
    else tmpa=a-1;

    ll ans=tmpb^tmpa;
    cout<<ans<<endl;

}