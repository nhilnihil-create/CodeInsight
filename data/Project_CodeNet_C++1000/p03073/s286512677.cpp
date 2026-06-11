#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(long long i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

int main(void)
{
    string s;
    cin >> s;
    ll n=s.size(), ans=INF;
    
    string a, b;
    ll tmp1=0,tmp2=0;
    rep(i,n){
        a += "10";
        b += "01";
    }
    rep(i,n){
        if(s[i] != a[i]) tmp1++;
        if(s[i] != b[i]) tmp2++;
    }
    ans = min(tmp1, tmp2);
    cout << ans << endl;
    return 0;
}