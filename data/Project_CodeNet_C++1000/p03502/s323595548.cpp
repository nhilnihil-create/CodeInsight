#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rep2(i,s,n) for(int i = (s); i < (n); ++i)
#define ll long long
#define ld long double
#define P pair<ll,ll>
#define all(v) v.begin(),v.end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

int main(void)
{
    ll n; cin>>n;
    string s=to_string(n);
    ll x=0;
    rep(i,s.size()){
        x+=s[i]-'0';
    }
    if(n%x==0) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}