#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000
typedef pair<ll, ll> pll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    map<string, int> ma;
    string prev = "unti";
    rep(i, N) {
        string s;
        cin >> s;
        if (i != 0) {
            if (ma[s] != 0) {
                cout << "No" << endl;
                return 0;
            }
            if (prev.back() != s.front()) {
                cout << "No" << endl;
                return 0;
            }
        }
        ma[s]++;
        prev = s;
    }

    cout << "Yes" << endl;
    return 0;
}