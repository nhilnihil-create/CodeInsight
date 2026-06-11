#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    int n;
    cin >> n;
    vector<ll> v(n+1);
    v[0] = 2;
    v[1] = 1;
    for(int i = 2; i <= n; i++){
        v[i] = v[i-1] + v[i-2];
    }
    cout << v[n] << endl;

    return 0;
}