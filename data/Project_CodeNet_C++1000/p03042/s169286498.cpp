#include <bits/stdc++.h>
using namespace std;

bool is_month(string s) { return "01" <= s && s <= "12"; }

bool is_year(string s) { return "00" <= s && s <= "99"; }

int main() {
    string S;
    cin >> S;
    string s1 = S.substr(0, 2);
    string s2 = S.substr(2, 2);
    if (is_month(s1) && is_year(s2) && is_year(s1) && is_month(s2))
        cout << "AMBIGUOUS" << endl;
    else if (is_month(s1) && is_year(s2))
        cout << "MMYY" << endl;
    else if (is_year(s1) && is_month(s2))
        cout << "YYMM" << endl;
    else
        cout << "NA" << endl;
    return 0;
}
