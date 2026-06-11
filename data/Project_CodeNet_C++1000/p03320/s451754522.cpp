#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using P = pair<int, int>;
using vec = vector<lint>;
using mat = vector<vector<int>>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"

constexpr int MOD = 1000000007;
const int INF = 1 << 30;

vec snuke;
int k;

int f(lint n) {
    int res = 0;

    while (n > 0) {
        res += (n%10);
        n /= 10;
    }

    return res;
}

long double g(lint n) {
    return (long double)n / f(n);
}

void build() {
    lint base = 1;
    lint suffix = 0;

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 300; j++) {
            if (i == 0 && j == 0) continue;
            snuke.push_back(suffix + base * j);
        }
        suffix += base * 9;
        base *= 10;
    }
}

int main() {
    cin >> k;

    build();

    sort(all(snuke));
    snuke.erase(unique(all(snuke)), snuke.end());

    int v = snuke.size();

    for (int i = 0; i < v; i++) {
        for (int j = i+1; j < v; j++) {
            if (g(snuke[i]) > g(snuke[j])) {
                snuke[i] = -1;
                break;
            }
        }
    }
    
    rep(i, k) {
        if (snuke[i] != -1) cout << snuke[i] << endl;
        else k++;
    }
    return 0;
}