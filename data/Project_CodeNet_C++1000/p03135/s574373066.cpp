#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef vector<vector<int>> vv;
typedef pair<int, int> P;

// input
int T, X;


void input() {
    cin >> T >> X;
}


int main() {
    input();
    double ans = double(T) / X;
    cout << ans << endl;
}
