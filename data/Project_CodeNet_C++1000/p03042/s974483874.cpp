#include <bits/stdc++.h>
using namespace std;

bool ism(int a) {
    return a != 0 && a <= 12;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int a = stoi(s.substr(0, 2));
    int b = stoi(s.substr(2, 2));

    if (ism(a) && ism(b)) {
        cout << "AMBIGUOUS" << endl;
    } else if (ism(a)) {
        cout << "MMYY" << endl;
    } else if (ism(b)) {
        cout << "YYMM" << endl;
    } else {
        cout << "NA" << endl;
    }
}
