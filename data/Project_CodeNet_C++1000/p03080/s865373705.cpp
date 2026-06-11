#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    int n;
    string s;
    cin >> n;
    cin >> s;
    int r = 0;
    int b = 0;
    rep(i, s.size()) {
        if(s[i] == 'R') r++;
        else b++;
    }
    if(r > b) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}