#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    string s;
    cin >> s;
    int w;
    cin >> w;
    int n = (s.size() + w - 1) / w;
    string t;
    rep(i, n) {
        t.push_back(s[w * i]);
    }
    cout << t << endl;
    return 0;
}