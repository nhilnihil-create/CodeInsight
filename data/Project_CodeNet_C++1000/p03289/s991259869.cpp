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
    string s; cin>>s;
    ll n=s.size();
    string ans="AC";
    if(s[0]!='A') ans="WA";
    ll cnt=0;
    for(int i=1;i<n;i++){
        if(isupper(s[i])){
            if(i==1 || i==n-1 || s[i]!='C') ans="WA";
            cnt++;
        }
    }
    if(cnt!=1) ans="WA";
    cout<<ans<<endl;
    return 0;
}