#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
#define DEBUG freopen("in.txt", "r", stdin);

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

int k;
string s;
int main() {
    cin >> s >> k;
    int n = s.length();
    char t = 'a';
    while (k) {
        set<string> st;
        for (int i = 0; i < n; ++i) {
            if (s[i] == t) {
                string ss;
                for (int j = 0; j < k && i + j < n; ++j) {
                    ss += s[i + j];
                    st.insert(ss);
                }
            }
        }
        if (st.size() >= k) {
            auto it = st.begin();
            while (k != 1) {
                --k;
                ++it;
            }
            cout << *it << endl;
            exit(0);
        }
        k -= st.size();
        ++t;
    }
    return 0;
}
