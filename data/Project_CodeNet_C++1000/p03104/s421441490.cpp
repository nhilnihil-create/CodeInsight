#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9 + 7;
const ll LINF = 1LL << 62;
const int INF = 1e9 + 7;

ll func(ll n){
    if(n&1){
        if((n / 2) & 1)n = 0;
        else n = 1;
    }
    else {
        n = (((n / 2) & 1) ^ n);
    }

    return n;
}

int main(){
    ll a, b;
    cin >> a >> b;

    if(a == 0)cout << b << endl;
    else cout << (func(a-1) ^ func(b)) << endl;
}