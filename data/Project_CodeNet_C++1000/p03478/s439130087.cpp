#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;


int main() {
    int n, a, b,some,sum=0;
    ll cnt = 0;
    cin >>n >> a >> b;
    REP(i, n) {
        some = i;
        sum = 0;
        while (some > 9) {
            sum += some % 10;
            some /= 10;
        }
        sum += some;
        if (a <= sum && sum <= b)cnt += i;
    }
    cout << cnt << endl;
    return 0;
}