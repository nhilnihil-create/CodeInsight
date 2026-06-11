#include <bits/stdc++.h>
#define INF 1e9
#define endl '\n'
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define FORE(i, a, b) for (int i = (a), e = (b); i < e; ++i)
#define RFORE(i, a, b) for (int i = (b)-1, e = (a); i >= e; --i)
#define ALL(x) (x).begin(), (x).end()
#define SORT(c) sort((c).begin(), (c).end())
#define SORTR(c) sort((c).begin(), (c).end(), greater<int>())
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> ABC(3);
    for (int i = 0; i < 3; i++) {
        cin >> ABC.at(i);
    }
    SORT(ABC);
    int p11 = ABC.at(2) - ABC.at(1);
    int p2  = 0;
    p2 += (ABC.at(2) - (ABC.at(0) + p11)) / 2;
    if ((ABC.at(1) - ABC.at(0)) % 2 == 1) {
        ++p11;
        ++p2;
    }
    cout << p11 + p2 << endl;
}
