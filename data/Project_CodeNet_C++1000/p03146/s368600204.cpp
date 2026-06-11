#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(it) it.begin(), it.end()
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPU(i, a, b, s) for(int i = a; i < b; i += s)
#define REPD(i, a, b, s) for(int i = a; i > b; i -= s)
#define endl "\n"

ll INF = 2e18;
ll MOD = 1e9 + 7;
int i, j, k, t;

int f(int x) {
    if(x % 2 == 0) {
        return x / 2;
    } else {
        return 3 * x + 1;
    }
}
int main() {

    int N = 1000001;
    int s;
    cin >> s;

    int now, next;
    vector<int> m(N, 0);
    now = s;
    m[s] = 1;

    REPU(i, 2, 1000001, 1) {
        next = f(now);
        if(m[next] == 0) {
            m[next] = 1;
        } else {
            cout << i << endl;
            exit(0);
        }
        now = next;
    }
}