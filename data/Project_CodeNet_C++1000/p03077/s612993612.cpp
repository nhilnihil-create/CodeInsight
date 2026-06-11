#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);
//const ll mod = 998244353;

vector<ll> dp(440000);

int main(void)
{
    ll n, mini=INF;
    cin >> n;
    vector<ll> t(5);
    rep(i,5){
        cin >> t[i];
        mini = min(mini, t[i]);
    }
    cout << 4 + (n+mini-1)/mini << endl;
    return 0;
}
