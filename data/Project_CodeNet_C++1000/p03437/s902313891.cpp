#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
using namespace std;

void solve() {
    ll x, y; cin >> x >> y;
    ll X = x;
    while(1){
        X += x;
        if(X%y != 0){
            cout << X << endl;
            return;
        }
        if(x%y == 0){
            cout << -1 << endl;
            return;
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    solve();
    return 0;
}
 
