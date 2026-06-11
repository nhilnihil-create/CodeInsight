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


int main(void)
{
    string s,k="keyence"; cin>>s;
    ll n=s.size();
    bool ok=false;
    rep(i,n+1)for(int j=i;j<n+1;j++){
        string t = s.substr(0,i)+s.substr(j);
        if(t==k) ok=true;
    }
    if(ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}