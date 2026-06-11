#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    string s;
    cin >> s;
    queue<char> q;
    rep(i,s.size()) {
        q.push(s[i]);
    }
    string a = "AKIHABARA";
    string b;
    rep(i,a.size()) {
        if (q.front() == a[i]) {
            b.push_back(q.front());
            q.pop();
        }
        else b.push_back('A');
    }
    string ans = "NO";
    if (q.empty() && a == b) ans = "YES";
    cout << ans << endl;
}