#include <bits/stdc++.h>
using namespace std;

int main() {
	string S;
    cin >> S;
    int up = (S[0] - '0') * 10 + S[1] - '0';
    int down = (S[2] - '0') * 10 + S[3] - '0';
    if (1 <= up && up <= 12) {
        if (1 <= down && down <= 12) {
            cout << "AMBIGUOUS" << endl;
        } else {
            cout << "MMYY" << endl;
        }
    } else if (1 <= down && down <= 12) {
        cout << "YYMM" << endl;
    } else {
        cout << "NA" << endl;
    }
}