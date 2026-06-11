#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

void dfs(int i, int k, int a, int b, int c, int &sum) {
    if (i == k) {
        sum = max(sum, a + b + c);
    } else {
        dfs(i+1, k, a*2, b, c, sum);
        dfs(i+1, k, a, b*2, c, sum);
        dfs(i+1, k, a, b, c*2, sum);
    }
}

int main() {
    int a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;
    int k;
    cin >> k;
    int sum = 0;
    dfs(0, k, a, b, c, sum);
    cout << sum << endl;
}