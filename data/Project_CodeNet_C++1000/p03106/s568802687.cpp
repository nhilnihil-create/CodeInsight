#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
    int a, b, k,cnt=0;
    cin >> a >> b >> k;
    vector<int>n;
    for (int i = 1; i <= min(a, b); i++) {
        if (a % i == 0 && b % i == 0)n.push_back(i);
    }
    auto itr = n.end();
    rep(i, k)itr--;
    cout <<  *itr<< endl;
    return 0;
}