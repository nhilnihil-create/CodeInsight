#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;

int main(){
    ll x, y;
    cin >> x >> y;

    ll res = 1;
    while(x * 2 <= y){
        x *= 2;
        res++;
    }
    cout << res << endl;
}