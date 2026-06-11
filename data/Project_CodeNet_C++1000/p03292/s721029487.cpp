#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;


vector<int> A;


void input() {
    A = vector<int>(3);
    rep(i, 3) cin >> A[i];
}


int main() {
    input();
    sort(A.begin(), A.end());
    int ans = A[2] - A[0];
    cout << ans << endl;
}
