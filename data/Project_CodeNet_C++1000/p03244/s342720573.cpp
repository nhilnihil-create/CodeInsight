#include <bits/stdc++.h>
#include <iterator>
using namespace std;

#define all(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;

int main() {
    ll n; cin >> n;
    V<P<ll, ll> > v1(100010), v2(100010);
    for(int i = 0; i < n; i++){
        ll v; cin >> v;
        if(i % 2 == 0){
            v1[v].first++;
            v1[v].second = v;
        }else{
            v2[v].first++;
            v2[v].second = v;
        }
    }

    sort(all(v1), greater<P<ll, ll>>());
    sort(all(v2), greater<P<ll, ll>>());

    ll tmp = 0;
    if(v1[0].second == v2[0].second){
        tmp = max(v1[0].first + v2[1].first, v1[1].first + v2[0].first);
    }else{
        tmp = v1[0].first + v2[0].first;
    }

    cout << n - tmp << endl;
}
