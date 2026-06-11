#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);


int main(void)
{
    ll r,g,b,n,cnt=0; cin>>r>>g>>b>>n;
    rep(i,n+1)rep(j,n+1){
        ll x=r*i+g*j;
        if(n-x>=0 && (n-x)%b==0) cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}