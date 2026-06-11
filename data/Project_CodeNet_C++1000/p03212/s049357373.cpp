#include <bits/stdc++.h>
using namespace std;

#define d(x) cerr << #x ":" << x << endl;
#define dd(x, y) cerr << "(" #x "," #y "):(" << x << "," << y << ")" << endl
#define rep(i, n) for (int i = (int)(0); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define dump(v)                  \
    cerr << #v ":[ ";            \
    for (auto macro_vi : v) {    \
        cerr << macro_vi << " "; \
    }                            \
    cerr << "]" << endl;
#define ddump(v)                           \
    cerr << #v ":" << endl;                \
    for (auto macro_row : v) {             \
        cerr << "[";                       \
        for (auto macro__vi : macro_row) { \
            cerr << macro__vi << " ";      \
        }                                  \
        cerr << "]" << endl;               \
    }
using lint       = long long;
const int INF    = 1e9;
const lint LINF  = 1e18;
const double EPS = 1e-10;

const int D = 9;
int N;

set<int> se;

void dfs(string& S) {
    if (S.size() == D) {
        string result = S;
        reverse(all(result));

        bool ok1 = false, ok2 = false, ok3 = false;
        for (auto c : result) {
            if (c == '7') ok1 = true;
            if (c == '5') ok2 = true;
            if (c == '3') ok3 = true;
        }
        int n753 = stoi(result);
        if (n753 <= N && ok1 && ok2 && ok3) { se.insert(n753); }
        return;
    }

    if (S.size() > 0 && S.back() == '0') {
        S.push_back('0');
        dfs(S);
        S.pop_back();
        return;
    } else {
        S.push_back('0');
        dfs(S);
        S.pop_back();

        S.push_back('7');
        dfs(S);
        S.pop_back();

        S.push_back('5');
        dfs(S);
        S.pop_back();
        S.push_back('3');
        dfs(S);
        S.pop_back();
    }
    return;
}

int main() {
    cin >> N;

    string S = "";
    dfs(S);

    cout << se.size() << endl;
    return 0;
}