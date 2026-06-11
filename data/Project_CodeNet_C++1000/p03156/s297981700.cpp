#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    vector<int> s(3);
    rep(i, n) {
        int p;
        cin >> p;
        if(p <= a) s[0]++;
        else if(p <= b) s[1]++;
        else s[2]++;
    }
    cout << min(s[0], min(s[1], s[2])) << endl;
    return 0;
}