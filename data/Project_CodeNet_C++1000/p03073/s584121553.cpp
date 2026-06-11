#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
const int mod = 1e9 + 7, A = 1e3 + 2;

int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string s;
    cin >> s;
    int cnt = 0, type = s[0] == '1' ? 1 : 0;
    for (int i = 1; i < (int)s.size(); i++) {
        if (s[i] == '1') {
            if (type == 1)
                cnt++, type = 0;
            else type = 1;
        }
        else if (s[i] == '0') {
            if (type == 0)
                cnt++, type = 1;
            else type = 0;
        }
    }
    cout << cnt;
    return 0;
}