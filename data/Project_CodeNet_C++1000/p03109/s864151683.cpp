/**
*    created: 23.05.2020 01:37:44
**/
#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    int y = stoi(s.substr(0,4));
    int m = stoi(s.substr(5,2));
    int d = stoi(s.substr(8,2));
    if (y < 2019) cout << "Heisei" << endl;
    else if (y > 2019) cout << "TBD" << endl;
    else {
        if (m < 4) cout << "Heisei" << endl;
        else if (m > 4) cout << "TBD" << endl;
        else {
            if (d <= 30) cout << "Heisei" << endl;
            else if (d < 30) cout << "TBD" << endl;
        }
    }
    return 0;
}