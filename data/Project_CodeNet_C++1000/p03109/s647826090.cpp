#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
    string s,ss;
    cin >> s;
    ss = s.substr(0, 4) + s.substr(5, 2) + s.substr(8, 2);
    int day = stoi(ss);
    int v = 20190430;
    if (v >= day)cout << "Heisei" << endl;
    else cout << "TBD" << endl;
    return 0;
}