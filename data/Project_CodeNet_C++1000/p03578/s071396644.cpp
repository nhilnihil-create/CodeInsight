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
unordered_map<ll,ll> d;
ll m;
ll t;

void error(){
    cout << "NO" << endl;
    exit(0);
}

int main(){
    cin >> n;
    for(ll i = 0;i < n;i++){
        ll d_;
        cin >> d_;
        d[d_]++;
    }
    cin >> m;
    for(ll i = 0;i < m;i++){
        cin >> t;
        if(d[t] > 0){
            d[t]--;
        }else{
            error();
        }
    }
    cout << "YES" << endl;
}
