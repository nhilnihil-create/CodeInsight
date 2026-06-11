#include <bits/stdc++.h>
using namespace std;

int check (string a) {
    vector<bool> check(3,false);
    for (int i = 0; i < (int)a.size(); i++) {
        if (a[i] == '3') check[0] = true;
        else if (a[i] == '5') check[1] = true;
        else if (a[i] == '7') check[2] = true;
        else return 0;
    }
    return (check[0] && check[1] && check[2] ? 1 : 0);
}

int dfs(string a, string n) {
    int res = check(a);
    if ((int)a.size() == (int)n.size()) return (a <= n ? res : 0);
    res += dfs(a + "3", n);
    res += dfs(a + "5", n);
    res += dfs(a + "7", n);
    return res;
}

int main() {
    string s; cin >> s;
    cout << dfs("", s) << endl;
    return 0;
}