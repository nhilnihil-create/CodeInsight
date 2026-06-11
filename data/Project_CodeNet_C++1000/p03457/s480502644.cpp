#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
    ll n;cin >>n;
    bool flg=true;
    ll pretime;
    ll pre;
    for (int i = 0; i < n; ++i) {
        ll t,x,y;
        cin >>t>>x>>y;
        ll sum=x+y;
        if(t%2!=sum%2)flg=false;
        if(t<sum)flg=false;
        if(i!=0) {
            if (abs(pre - sum) > t - pretime)flg=false;
        }
        pretime=t;
        pre=sum;
    }
    if(flg)puts("Yes");
    else puts("No");
    return 0;
}

