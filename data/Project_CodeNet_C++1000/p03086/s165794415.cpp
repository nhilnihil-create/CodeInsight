#include <iostream>
#include <string>
#include <vector>

#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)

using lint = long int;
using llint = long long int;
using namespace std;

int main() {
    fastIO;
    string s;
    cin >> s;

    int ans = 0;
    for (size_t i = 0; i < s.size(); i++) {
        int cnt = 0;
        for (size_t j = i; j < s.size(); j++) {
            char ch = s.at(j);
            if (ch == 'A' || ch == 'T' || ch == 'G' || ch == 'C') {
                cnt++;
                ans = max(ans, cnt);
            } else {
                cnt = 0;
            }
        }
    }
    cout << ans << endl;
}

