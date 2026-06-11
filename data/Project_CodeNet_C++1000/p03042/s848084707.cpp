#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    string s;
    cin >> s;
    int a = (s[0] - '0')*10 + (s[1] - '0');
    int b = (s[2] - '0')*10 + (s[3] - '0');
    bool at = (1 <= a && a <= 12);
    bool bt = (1 <= b && b <= 12);
    if (at && bt) cout << "AMBIGUOUS" << endl;
    else if (at) cout << "MMYY" << endl;
    else if (bt) cout << "YYMM" << endl;
    else cout << "NA" << endl;
    return 0;
}