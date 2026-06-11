#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 2, 0);
    rep(i, n) cin >> a[i + 1];
    int sum = 0;
    rep(i, n + 1){
        sum += abs(a[i] - a[i + 1]);
    }

    int ans = sum;
    for(int i = 1; i <= n ; i++){
        int cost = sum;
        cost -= abs(a[i] - a[i - 1]) + abs(a[i] - a[i + 1]);
        cost += abs(a[i - 1] - a[i + 1]);
        cout << cost << endl;
    }
}