#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll A, B, C;
int main() {
    cin >> A >> B >> C;


    if (A + B >= C - 1) {
        cout << B + C << endl;
    } else {
        cout << A + B + 1 + B << endl;
    }
}