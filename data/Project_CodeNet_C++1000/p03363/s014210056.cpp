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

int main(){
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;++i){
        cin>>a[i];
    }

    vector<ll> s(n+1);
    s[0] = 0;
    for(ll i=0;i<n;++i){
        s[i+1] = s[i] + a[i];
    }
    map<ll, ll> num;
    for(ll i=0;i<n+1;++i){
        num[s[i]]++;
    }
    ll ans=0;
    for(auto val : num){
        ll flag = val.second;
        ans += flag*(flag-1)/2;
    }
    cout<<ans<<endl;

    return 0;
}