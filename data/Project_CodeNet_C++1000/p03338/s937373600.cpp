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

ll func(string s,string t){
    ll ans=0;
    for(char c='a';c<='z';c++){
        bool l=false,r=false;
        rep(i,s.size()){
            if(s[i]==c) l=true;
        }
        rep(i,t.size()){
            if(t[i]==c) r=true;
        }
        if(l&&r) ++ans;
    }
    return ans;
}

int main(void)
{
    ll n; cin>>n;
    string s; cin>>s;
    ll ans=0;
    rep(i,n+1){
        ll cnt=func(s.substr(0,i),s.substr(i));
        ans=max(ans,cnt);
    }
    cout<<ans<<endl;
    return 0;
}