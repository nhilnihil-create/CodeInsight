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
    int k, cnt = 0, tmp = 0;
    cin >> s >> k;
    if (s[0] != '1')cout << s[0] << endl;
    else {
        rep(i, s.size()) {
            if (s[i] == '1')cnt++;
            else
            {
                tmp = s[i] - '0';
                break;
            }
        }
        if (cnt >= k)cout << 1 << endl;
        else cout << tmp << endl;
    }
    return 0;
}