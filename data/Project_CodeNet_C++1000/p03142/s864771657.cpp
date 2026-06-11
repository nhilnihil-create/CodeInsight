// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

vector<vector<int>> v;

int main(int argc, char** argv) {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> v(N, vector<int>());
    vector<int> input(N, 0);
    vector<int> ans(N, 0);

    rep(i, N - 1 + M) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        v[a].push_back(b);
        input[b]++;
    }

    stack<int> st;
    rep(i, N) {
        if (input[i] == 0)
            st.push(i);
    }

    while (!st.empty()) {
        int i = st.top();
        st.pop();
        for (int& j : v[i]) {
            input[j]--;
            if (input[j] == 0) {
                st.push(j);
                // printf("ans[%d]=%d\n", j, i + 1);
                ans[j] = i + 1; // node number is index + 1
            }
        }
    }
    rep(i, N) { cout << ans[i] << endl; }

    // rep(i, E) {
    //     printf("%d: [in] %d, [out] ", i, input[i]);
    //     for (auto& j : v[i]) {
    //         printf("->%d,", j);
    //     }
    //     printf("\n");
    // }
    return 0;
}
