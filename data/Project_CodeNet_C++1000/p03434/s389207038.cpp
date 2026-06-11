#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef vector<vector<int>> vv;
typedef pair<int, int> P;

// input
int N;
vector<int> A;


void input() {
    cin >> N;
    A = vector<int>(N);
    rep(i, N) cin >> A[i];
}


int main() {
    input();
    sort(A.rbegin(), A.rend());
    int s = 0;
    rep(i, N) s += A[i];
    int a = 0;
    for (int i = 0; i < N; i += 2) a += A[i];
    int ans = a - (s - a);
    cout << ans << endl;
}
