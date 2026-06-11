#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    string str;
    cin >> str;

    int chk = 0;

    int yy = stoi(str.substr(0, 2));
    int mm = stoi(str.substr(2));
    if ((yy >= 0 && yy <= 99) && (mm >= 1 && mm <= 12)) chk += 1;
    if ((mm >= 0 && mm <= 99) && (yy >= 1 && yy <= 12)) chk += 2;

    if (chk == 0) cout << "NA";
    else if(chk == 1) cout << "YYMM";
    else if(chk == 2) cout << "MMYY";
    else if(chk == 3) cout << "AMBIGUOUS";
    //
}
