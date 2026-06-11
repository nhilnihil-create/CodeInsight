#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;


int main() {
    string s;
    int mins = 10000000;
    cin >> s;
    int len = s.size();
    rep(i, len - 2) {
        mins = min(mins, abs(753 - stoi(s.substr(i, 3))));
    }
    cout << mins << endl;
    return 0;
}
