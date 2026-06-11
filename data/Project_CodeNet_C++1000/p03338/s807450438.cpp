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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int count;
    int ans = -1;
    string t, u;
    // vector<bool> a(26), b(26);
    bool a[30], b[30];
    for(int i = 1; i < n; i++) {
        fill(a, a + 26, false);
        fill(b, b + 26, false);
        count = 0;
        string t = s.substr(0, i), u = s.substr(i, n - i);
        for(auto p : t) a[p - 'a'] = true;
        for(auto p : u) b[p - 'a'] = true;
        rep(j, 26) if(a[j] && b[j]) count++;
        ans = max(ans, count);
    }
    cout << ans << endl;
}