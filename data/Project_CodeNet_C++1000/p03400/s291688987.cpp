#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;


int main() {
    int n, d, x,a,cnt=0,tmp=0;
    cin >> n >> d >> x;
    rep(i, n) {
        cin >> a;
        int index = 0;
        while (1) {
            tmp = index * a + 1;
            if (tmp > d)break;
            else index++;
        }
        cnt += index;
    }
    cout << cnt + x << endl;
    return 0;
}