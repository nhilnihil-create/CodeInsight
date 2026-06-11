#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using P = pair<int, int>;
using vec = vector<int>;
using mat = vector<vector<int>>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"

constexpr int MOD = 1000000007;
const int INF = 1 << 30;

bool is_number(char c) {
    int d = c - '0';
    return d >= 0 && d <= 9;
}

void say_no() {
    cout << "No" << endl;
    exit(0);
}

int main() {
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    int n = a+b+1;

    rep(i, n) {
        if (i < a) {
            if (!is_number(s[i])) say_no();
        }
        else if (i > a) {
            if (!is_number(s[i])) say_no();
        }
        else {
            if (s[i] != '-') say_no();
        }
    }

    cout << "Yes" << endl;
    return 0;
}