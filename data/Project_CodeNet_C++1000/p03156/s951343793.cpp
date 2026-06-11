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
    ll n,a,b; cin>>n>>a>>b;
    vector<ll> x(3,0);
    rep(i,n){
        ll p; cin>>p;
        if(p<=a) x[0]++;
        else if(p<=b) x[1]++;
        else x[2]++;
    }
    cout << min({x[0],x[1],x[2]}) << endl;
    return 0;
}