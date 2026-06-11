#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < (int)(n); i++)
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N;
    cin >> N;

    map<int, int> D;
    int di;
    rep(i, N) {
        cin >> di;
        if (D.count(di)) D[di]++;
        else D[di] = 1;
    }

    int M;
    cin >> M;

    string ans = "YES";
    int ti;
    rep(i, M) {
        cin >> ti;
        if (D.count(ti) && D[ti] > 0) D[ti]--;
        else ans = "NO";
    }

    cout << ans << endl;

    return 0;
}