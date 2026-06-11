#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main() {
    ll a,b,c,k;cin >>a>>b>>c>>k;
    ll ans;
    if(a-b<=1e18){
        ans=a-b;
    }
    else {
        puts("Unfair");
        return 0;
    }
    if(k%2==1)ans*=-1;
    cout <<ans <<endl;
    return 0;
}

