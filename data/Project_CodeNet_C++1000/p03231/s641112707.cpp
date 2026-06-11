#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
    ll n,m;cin>>n>>m;
    string s,t;cin >>s>>t;
    ll g=__gcd(n,m);
    ll l=n*m/g;
    ll a=n/g;
    ll b=m/g;
    for (int i = 0; i < g; ++i) {
        if(s[a*i]!=t[b*i]){
            cout <<-1<<endl;
            return 0;
        }
    }
    cout <<l<<endl;
}
