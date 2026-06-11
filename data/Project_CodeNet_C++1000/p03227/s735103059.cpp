#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

int main() {
    string S;
    cin >> S;
    if (S.size() == 2) {
        cout << S << endl;
    } else {
        reverse(S.begin(), S.end());
        cout << S << endl;
    }
}