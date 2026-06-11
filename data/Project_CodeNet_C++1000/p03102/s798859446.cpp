#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
ll factorial(int i) {       //階乗
    if (i == 0) return 1;
    return (factorial(i - 1)) * i;
}

int main() {
    int n, m, c;
    cin >> n >> m >> c;
    vector<int> b(m);
    rep(i, m) cin >> b[i];
    vector<vector<int>> a(n, vector<int> (m));
    rep(i, n) {
        rep(j, m) cin >> a[i][j];
    }
    int count = 0;
    int sum;
    rep(i, n) {
        sum = 0;
        rep(j, m) {
            sum += a[i][j] * b[j];
        }
        sum += c;
        if(sum > 0) count++;
    }
    cout << count << endl;
}