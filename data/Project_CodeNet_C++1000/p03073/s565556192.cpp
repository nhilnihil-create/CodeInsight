#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define PB push_back
#define MP make_pair

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    int ans1 = 0;
    int ans2 = 0;
    int cur = s[0] - '0';
    for (int i = 1; i < s.size(); ++i) {
        int c = s[i] - '0';
        if (c != !cur) {
            ++ans1;
            cur = !cur;
        } else cur = c;
    }
    cur = !(s[0] - '0');
    for (int i = 1; i < s.size(); ++i) {
        int c = s[i] - '0';
        if (c != !cur) {
            ++ans2;
            cur = !cur;
        } else cur = c;
    }
    ++ans2;
    cout << min(ans1, ans2) << "\n";
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* print new lines
*/