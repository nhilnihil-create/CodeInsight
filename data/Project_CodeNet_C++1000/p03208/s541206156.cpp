#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
    int n, k,mins=1000000000;
    cin >> n >> k;
    vector<int>h(n);
    rep(i, n)cin >> h[i];
    sort(all(h));
    rep(i, n - k+1) {
        mins = min(mins, abs(h[k-1+i] - h[i]));
        //mins = min(mins, abs(h[k] - h[k-i]));
    }
    cout << mins << endl;
}