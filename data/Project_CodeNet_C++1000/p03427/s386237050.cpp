#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    string s = to_string(n);
    int d = s.size();
    long long a = 0, o = 1;
    for (int i = 0; i < d; i++) {
        a += 9*o;
        if (i != d-1) o *= 10;
    }
    while (a > n) a -= o;
    string t = to_string(a);
    int ans = 0;
    for (int i = 0; i < t.size(); i++) {
        ans += t[i] - '0';
    }
    cout << ans << endl;
}