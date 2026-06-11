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
    cin>>s;
    ll z=0,o=0,n=s.size();
    rep(i,n){
        if(s[i]=='0') z++;
        else o++;
    }
    cout << 2*min(z,o) << endl;
    return 0;
}