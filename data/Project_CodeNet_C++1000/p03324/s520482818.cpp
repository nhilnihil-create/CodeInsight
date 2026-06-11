#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

ll f(ll x){
    if(x%100!=0) return 0;
    else return f(x/100)+1;
}

int main(void)
{
    ll d,n; cin>>d>>n;
    ll cnt=0,i=1;
    while(true){
        if(f(i)==d){
            cnt++;
        }
        if(cnt==n){
            cout<<i<<endl;
            return 0;
        }
        i++;
    }
    return 0;
}