#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
using namespace std;
const long long int INF = 1e6;
const long long int mod = 1e9+7;
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
    string s;
    cin>>s;

    map<char, ll> t;
    for(ll i=0;i<n;++i){
        t[s[i]]++;
    }
    ll ans=1;
    for(auto val : t){
        ans *= val.second + 1;
        ans %= mod;
    }
    ans--;
    cout<<ans<<endl;

    return 0;
}