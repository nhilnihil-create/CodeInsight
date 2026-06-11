#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int fi, se;
    fi = (s[0] - '0') * 10 + s[1] -'0';
    se = (s[2] - '0') * 10 + s[3] -'0';
    if (0 < fi && fi <= 12 && 0 < se && se <= 12){
        cout << "AMBIGUOUS" << endl;
    }
    else if (0 < fi && fi <= 12)
    {
        cout << "MMYY" << endl;
    }
    else if (0 < se && se <= 12)
    {
        cout << "YYMM" << endl;
    }
    else
    {
        cout << "NA" << endl;
    }
}

int main() {
    solve();
    return 0;
}