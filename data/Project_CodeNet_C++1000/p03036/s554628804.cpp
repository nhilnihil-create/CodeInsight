#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rep2(i,n) for (int i = 1; i <= (n); i++)
using ll = long long;
using Grid = vector<vector<int>>;

int main(){
    int r, D;
    ll x;
    cin >> r >> D >> x;
    rep(i, 10) {
        x = r * x - D;
        cout << x << endl;
    }
}