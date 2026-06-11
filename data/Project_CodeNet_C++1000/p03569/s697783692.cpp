#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pint = pair<int, int>;
using vi = vector<int>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

const int MOD = 1000000007;
const int INF = 1 << 30;

int solve(string s) {
    int res = 0;

    for (int i = 0, j = s.size()-1; i < j; ) {
        if (s[i] == s[j]) { i++; j--; }
        else if (s[i] == 'x') { res++; i++; }
        else if (s[j] == 'x') { res++; j--; }
        else { return -1; }
    }

    return res;
}

int main() {
    string s;
    cin >> s;
    
    cout << solve(s) << endl;
    return 0;
}
