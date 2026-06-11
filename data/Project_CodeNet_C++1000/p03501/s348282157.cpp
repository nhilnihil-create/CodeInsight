#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef vector<vector<int>> vv;
typedef pair<int, int> P;

// input
int N, A, B;


void input() {
    cin >> N >> A >> B;
}


int main() {
    input();
    int ans = min(A * N, B);
    cout << ans << endl;
}
