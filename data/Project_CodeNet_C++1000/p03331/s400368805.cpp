#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
using namespace std;
const long long int INF = 1e6;
typedef pair<ll,ll> pairs;
vector<pairs> p;


ll gcd(ll a,ll b){
    if (a%b==0)return(b);
    else return(gcd(b,a%b));
}

ll keta(ll N){
    int tmp{};
    while( N > 0 ){
        tmp += ( N % 10 );
        N /= 10;
    }
    N = tmp;
    return N;
}

// ------------------------------------

int main(){
    ll n;
    cin>>n;
    ll ans=INF;
    for(ll i=1;i<=n/2;++i){
        ll a=i;
        ll b=n-i;
        ans = min(ans, keta(a)+keta(b));
    }
    cout<<ans<<endl;

    return 0;
}