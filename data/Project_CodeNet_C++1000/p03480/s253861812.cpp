#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool solve(int k, string s) {
    vector<int> v(s.size() + 1, 0);
    int n = s.size();
    for (int i = n - k; i < k; i++) {
        v[i] = i ? v[i - 1] + v[i] : 0;
        int x = s[i] - '0';
        if ((x + v[i]) % 2 != 0) {
            if (i + k - 1 < s.size())
                v[i]++, v[i + k]--;
            else
                return false;
        }
    }
    return true;
}

int binary_search(int ok, int ng, string s) {
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if (solve(mid, s)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    return ok;
}

int main() {
    string s;
    cin >> s;
    cout << binary_search(1, s.size() + 1, s) << endl;
    return 0;
}