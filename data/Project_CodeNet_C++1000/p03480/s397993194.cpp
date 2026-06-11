#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int Solve() {
    string s;
    cin >> s;

    const int n = s.size();
    int k = 0;
    if (n % 2 == 0) {
        int r = n / 2, l = r - 1;
        while (0 <= l - k && r + k < n) {
            if (s[r] != s[l - k] || s[l] != s[r + k]) break;
            ++k;
        }
    }
    else {
        int mid = n / 2;
        while (0 <= mid - k && mid + k < n) {
            if (s[mid] != s[mid - k] || s[mid] != s[mid + k]) break;
            ++k;
        }
    }
    return n / 2 + k;
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    cout << Solve() << endl;

    return 0;
}
