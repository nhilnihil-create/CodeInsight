#include <bits/stdc++.h>
using namespace std;

string a;
string myans;
void dfs(int ans, int i, int lim, string s) {
    if(lim >= 3) {
        if(ans == 7) {
            myans = s;
        }
        return;
    }
    string s1 = s + "+" + a[i];
    string s2 = s + "-" + a[i];
    int ans1 = ans + (a[i] - '0');
    int ans2 = ans - (a[i] - '0');
    dfs(ans1, i + 1, lim + 1, s1);
    dfs(ans2, i + 1, lim + 1, s2);
}
void solve() {
    cin >> a;
    string t;
    t += a[0];
    dfs(a[0] - '0', 1, 0, t);
    cout << myans;
    cout << "=7";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
