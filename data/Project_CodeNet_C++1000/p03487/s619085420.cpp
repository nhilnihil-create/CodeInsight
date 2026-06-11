#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;


int main() {
    int n,a,cnt=0;
    map<int, int>mp;
    cin >> n;
    rep(i, n) {
        cin >> a;
        mp[a]++;
    }
    for (auto p : mp) {
        if (p.first == p.second)continue;
        cnt += p.first > p.second ? p.second : p.second - p.first;
    }
    cout << cnt << endl;
    return 0;
}
