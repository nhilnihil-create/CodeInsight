#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
    string n;
    cin >> n;
    string ans = "NA";
    bool mb = false, ub = false;
    int mae = stoi(n.substr(0, 2));
    int usiro = stoi(n.substr(2, 2));
    if (1 <= mae && mae <= 12)mb = true;
    if (1 <= usiro && usiro <= 12)ub = true;
    if (mb && ub)ans = "AMBIGUOUS";
    else if (mb)ans = "MMYY";
    else if (ub)ans = "YYMM";

    cout << ans << endl;
    return 0;
}