#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int n, q;
    cin >> n >> q;
    string str;
    cin >> str;

    vector<int> s(n+1, 0);
    for (int i = 0; i < str.length(); ++i) {
        if (i+1 < n && str[i] == 'A' && str[i+1] == 'C') s[i+1] = s[i] + 1;
        else s[i+1] = s[i];
    }

    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        cout << s[r] - s[l] << endl;
    }
    return 0;
}