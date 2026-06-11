#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n,m;
    cin >> n >> m;

    ll t = 100*n + 1800*m;

    cout << pow(2,m) * t << endl;

    
}