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

const int N = 1e5 + 5;
int n;
char c;
unordered_set<char> st;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> c;
        st.insert(c);
    }
    if (st.size() == 3)
        cout << "Three" << endl;
    else
        cout << "Four" << endl;
    return 0;
}
