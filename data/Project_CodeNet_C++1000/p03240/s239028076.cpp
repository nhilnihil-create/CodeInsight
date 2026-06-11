#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> v1;
typedef vector<v1> v2;
typedef vector<v2> v3;

typedef unordered_map<ll, unordered_map<ll, ll>> graph;

const ll INF = 1ll << 50;
const ll mod = 1000000007;

ll n;
vector<tuple<ll,ll,ll>> info;

void solve(ll cx, ll cy){
    ll x,y,h;
    tie(h,x,y) = info[0];
    ll ch = h + abs(x-cx) + abs(y-cy);
    // cerr << ch << endl;
    for(ll i = 1;i < n;i++){
        tie(h,x,y) = info[i];
        // cerr << x << " " << y << " " << h << endl;
        // cerr << max(ch-abs(x-cx)-abs(y-cy), 0ll) << endl;
        if(h != max(ch-abs(x-cx)-abs(y-cy), 0ll)){
            return;
        }
    }
    cout << cx << " " << cy << " " << ch << endl;
    exit(0);
}


int main(){
    cin >> n;
    info = vector<tuple<ll,ll,ll>>(n);
    for(ll i = 0;i < n;i++){
        ll x,y,h;
        cin >> x >> y >> h;
        info[i] = make_tuple(h,x,y);

    }
    sort(info.rbegin(),info.rend());
    for(ll i = 0;i <= 100;i++){
        for(ll j = 0;j <= 100;j++){
            solve(i,j);
        }
    }
    // solve(2,2);
}
