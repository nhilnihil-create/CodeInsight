#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    string s;
    cin >> s;
    int c = atoi(s.substr(0,2).c_str());
    int t = atoi(s.substr(2,2).c_str());
    bool a = 0 < c && c <= 12;
    bool b = 0 < t && t <= 12;
    if (a && b) cout << "AMBIGUOUS" << endl;
    else if (!a && !b) cout << "NA" << endl;
    else if (!a && b) cout << "YYMM" << endl;
    else if (a && !b) cout << "MMYY" << endl;
    return 0;
}
