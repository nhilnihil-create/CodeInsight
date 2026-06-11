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
    vector<ll> a(n);
    ll ans=0;
    for(ll i=0;i<n;++i){
        cin>>a[i];
        if(i==0){
            continue;
        }
        if(a[i]==a[i-1]){
            a[i] = -1;
            ans++;
        }
    }
    cout<<ans<<endl;

    return 0;
}