#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef vector<vector<int>> vv;
typedef pair<int, int> P;

// input
int A, B, C;


void input() {
    cin >> A >> B >> C;
}


int main() {
    input();
    int ans;
    if (A == B) ans = C;
    else if (A == C) ans = B;
    else ans = A;
    cout << ans << endl;
}
