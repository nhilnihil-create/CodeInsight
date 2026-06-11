#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
    int d,n,cnt=0,cntn=0,s,u=0;
    cin >> d >> n;
    u = 1 * pow(100, d);
    for (int i = (1*pow(100,d)); i < 1000000000; i += u) {
        cnt = 0;
        s = i;
        while (s % 100 == 0) {
            cnt++;
            s /= 100;
        }
        if (cnt == d)cntn++;
        if (cntn == n) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}