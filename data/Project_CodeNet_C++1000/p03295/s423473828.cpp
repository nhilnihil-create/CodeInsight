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

ll n,m;
vector<tuple<ll,ll>> ab;
ll ans = 0;

int main(){
    cin >> n >> m;
    ab = vector<tuple<ll,ll>>(m);
    for(ll i = 0;i < m;i++){
        ll a,b;
        cin >> a >> b;
        ab[i] = make_tuple(a,b);
    }
    sort(ab.begin(),ab.end());
    ll r = INF;
    for(ll i = 0;i < m-1;i++){
        ll a,b,next_a,next_b;
        tie(a,b) = ab[i];
        tie(next_a,next_b) = ab[i+1];
        r = min(r,b);
        if(next_a >= r){
            ans++;
            r = INF;
        }


    }
    ans++;
    cout << ans << endl;
}
