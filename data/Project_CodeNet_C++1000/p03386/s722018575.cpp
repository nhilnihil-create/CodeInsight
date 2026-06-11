#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;


int main() {
    int a,b,k;
    set<int>seq;
    cin >> a >> b >> k;
    for (int i = a; i < a + k; i++) {
        if (a <= i && i <= b) {
            cout << i << endl;
            seq.insert(i);
        }
    }
    for (int i = b - k + 1; i <= b; i++) {
        if (a <= i && i <= b) {
            if (!seq.count(i))cout << i << endl;
        }
    }

    return 0;
}