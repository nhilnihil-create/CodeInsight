#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int first = stoi(s.substr(0,2));
    int second = stoi(s.substr(2));

    if (0<first && first <=12) {
        if (0 < second && second <= 12)
            cout << "AMBIGUOUS" << endl;
        else
            cout << "MMYY" << endl;
    }
    else {
        if (0 < second && second <= 12)
            cout << "YYMM" << endl;
        else
            cout << "NA" << endl;
    }
}