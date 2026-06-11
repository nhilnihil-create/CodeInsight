#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

int main() {
    int a, b, k; cin >> a >> b >> k;
    int abmin = min(a, b);

    vector<int> rtn;
    for (int i = 1; i <= abmin; ++i) {
        if (a % i == 0 && b % i == 0) {
            rtn.push_back(i);
        }
    }
    sort(rtn.begin(), rtn.end());
    reverse(rtn.begin(), rtn.end());
    cout << rtn[k-1] << endl;
}
