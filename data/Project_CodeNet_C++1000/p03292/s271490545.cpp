#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
//cout << setprecision(20) << 

int main() {
    vector<int> a(3);
    for (int i = 0; i < 3; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int sum = 0;
    for (int i = 1; i < 3; ++i) {
        sum += a[i] - a[i - 1];
    }
    cout << sum << endl;
}