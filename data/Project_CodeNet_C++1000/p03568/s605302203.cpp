#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000
typedef pair<ll, ll> pll;

int cnt = 0;
void dfs(vector<int> &A, vector<int> B, int N) {
    // 数列の長さが N に達したら打ち切り
    if (A.size() == N) {
        rep(i, N) {
            if (A[i] % 2 == 0) {
                cnt++;
                break;
            }
        }
        return;
    }

    // 0からMまでの数字
    for (int v = B[A.size()] - 1; v <= B[A.size()] + 1; ++v) {
        A.push_back(v);
        dfs(A, B, N);
        A.pop_back();
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> A, B(N);
    rep(i, N) { cin >> B[i]; }

    dfs(A, B, N);
    cout << cnt << endl;
}