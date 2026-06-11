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
    ll n,ans=0,tmp=0; cin>>n;
    string s=to_string(n);
    ans = 9*(s.size()-1) + s[0]-'1';
    rep(i,s.size()){
        tmp += s[i]-'0';
    }
    cout << max(ans,tmp) << endl;
    return 0;
}