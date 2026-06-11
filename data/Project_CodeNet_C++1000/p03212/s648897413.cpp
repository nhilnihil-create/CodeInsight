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

int N;
string S;
vector<char> P{'3', '5', '7'};

lint cnt = 0;
void dfs(int i, string& X) {

    if (0 < i) {
        bool wit_3 = false, wit_5 = false, wit_7 = false;
        for (int j = 0; j < X.size(); j++) {
            if (X[j] == '3') wit_3 = true;
            if (X[j] == '5') wit_5 = true;
            if (X[j] == '7') wit_7 = true;
        }
        bool less = (stoi(X) <= stoi(S));
        if (wit_3 && wit_5 && wit_7 && less) {
            cnt++;
            // dump(X);
        }
    }

    if (i == N) { return; }

    for (int j = 0; j < 3; j++) {
        X.push_back(P[j]);
        dfs(i + 1, X);
        X.pop_back();
    }
}

int main() {
    cin >> S;
    N = S.size();

    string A = "";
    dfs(0, A);
    cout << cnt << endl;

    return 0;
}