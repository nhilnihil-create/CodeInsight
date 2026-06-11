#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <cmath>
using namespace std;
using ll = long long;
const int INF = 1e9;


int main() {
    int N, K;
    cin >> N >> K;

    vector<ll> v(K, 0);
    for(ll i=1; i<=N; ++i) {
        v[i%K]++;
    }

    ll res=0;
    res += (v[0]*v[0]*v[0]);

    if(K%2==0) {
        res += (v[K/2]*v[K/2]*v[K/2]);
    }

    cout << res << endl;
}
