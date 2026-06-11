#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
const ll MOD = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);

int main(void)
{
    vector<ll> a(5);
    rep(i,5) cin>>a[i];
    ll ans=INF;
    vector<ll> p={0,1,2,3,4};
    do{
        ll tmp=0;
        rep(i,5){
            while(tmp%10!=0) tmp++;
            tmp+=a[p[i]];
        }
        ans=min(ans,tmp);
    }while(next_permutation(p.begin(),p.end()));
    cout<<ans<<endl;
    return 0;
}