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
    ll a,b; string s;
    cin>>a>>b>>s;
    bool ok=true;
    rep(i,s.size()){
        if(s[a]!='-') ok=false;
        else if(i==a) continue;
        else if(!('0'<=s[i] && s[i]<='9')) ok=false; 
    }
    if(ok) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}