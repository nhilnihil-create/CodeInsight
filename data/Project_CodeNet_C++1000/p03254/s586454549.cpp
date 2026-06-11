#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;


int main() {
    ll n,x,index=0,cnt=0;
    cin >> n >> x;
    vector<ll>child(n);
    vector<ll>snake_child(n);
    rep(i, n)cin >> child[i];
    sort(all(child));
    rep(i, n) {
        if (x >= child[i])x -= child[i];
        else break;
        if (i != n - 1)snake_child[i] = child[i];
        else snake_child[i] = x+child[i];
    }
    rep(i, n)if (child[i] == snake_child[i])cnt++;
    cout << cnt << endl;
    return 0;
}