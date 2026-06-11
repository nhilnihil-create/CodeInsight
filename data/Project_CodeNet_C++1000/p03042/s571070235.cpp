#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    string S;
    cin >> S;

    bool f = ((S.substr(0, 2) >= "01") && (S.substr(0, 2) <= "12"));
    bool r = ((S.substr(2, 2) >= "01") && (S.substr(2, 2) <= "12"));
    if (f && r) cout << "AMBIGUOUS" << endl;
    else if (f && !r) cout << "MMYY" << endl;
    else if (!f && r) cout << "YYMM" << endl;
    else cout << "NA" << endl;
    return 0;
}