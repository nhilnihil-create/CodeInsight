#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000
typedef pair<ll, ll> pll;

ll cnt = 0;

int d[3] = {3, 7, 5};

void dfs(vector<int> &A, int n, int N) {
    // 数列の長さが N に達したら打ち切り
    if (A.size() == n + 1)
        return;

    if (A.size() >= 3) {
        bool j1 = 0, j2 = 0, j3 = 0;
        ll exp = 1;
        ll num = 0;
        for (int i = A.size() - 1; i > -1; i--) {
            if (A[i] == 3)
                j1 = 1;
            else if (A[i] == 7)
                j2 = 1;
            else if (A[i] == 5)
                j3 = 1;
            num += A[i] * exp;
            exp *= 10;
        }
        if (num <= N && j1 && j2 && j3) {
            cnt++;
        }
    }

    // 0からMまでの数字
    for (int v = 0; v < 3; ++v) {
        A.push_back(d[v]);
        dfs(A, n, N);
        A.pop_back();
    }
}

int main() {
    ll N;
    cin >> N;
    int n = to_string(N).size();
    vector<int> A;
    dfs(A, n, N);
    cout << cnt << endl;
}