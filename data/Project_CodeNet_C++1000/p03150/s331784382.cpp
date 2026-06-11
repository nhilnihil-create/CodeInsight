#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 1'010'000'000'000'000'017LL;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main() {
    // AtCoder
    // template
    string s;
    cin >> s;
    bool ans = false;
    string k = "keyence";
    rep(i, 8) {
        // cout << s.substr(0, i) << ' ' << s.substr(s.size() - (7 - i - 1) - 1)
        //      << endl;
        if((s.substr(0, i) == k.substr(0, i) &&
            s.substr(s.size() - (7 - i - 1) - 1) ==
                k.substr(k.size() - (7 - i - 1) - 1)))

            ans = true;
    }

    if(ans)
        cout << "YES";
    else
        cout << "NO";
}
