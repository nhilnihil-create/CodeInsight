#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;

int main() {
    vector<int> a(3);
    for (int i = 0; i < 3; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int sum = 0;
    for (int i = 1; i < 3; i++) {
        sum += a[i] - a[i - 1];
    }
    cout << sum << endl;
    return 0;
}