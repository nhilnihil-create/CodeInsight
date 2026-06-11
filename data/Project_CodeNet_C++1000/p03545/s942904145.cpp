#include <bits/stdc++.h>
using namespace std;

int main() {
    string ABCD;
    cin >> ABCD;
    int a, b, c, d;
    a = (int)ABCD.at(0) - 48;
    b = (int)ABCD.at(1) - 48;
    c = (int)ABCD.at(2) - 48;
    d = (int)ABCD.at(3) - 48;
    int n = 3;
    vector<int> answerCal(3);
    for (int bit = 0; bit < (1 << n); bit++) {
        int total = 0;
        vector<int> cal(3);
        if (bit & 1) {
            cal.at(0) = 1;
            total += a + b;
        } else {
            total += a - b;
        }
        // cout << total << endl;
        if (bit & 2) {
            cal.at(1) = 1;
            total += c;
        } else {
            total -= c;
        }
        // cout << total << endl;
        if (bit & 4) {
            cal.at(2) = 1;
            total += d;
        } else {
            total -= d;
        }
        // cout << total << endl;
        if (total == 7) {
            answerCal = cal;
            break;
        }
    }
    string answer = "";
    answer += to_string(a);
    answerCal.at(0) == 1 ? answer += "+" : answer += "-";
    answer += to_string(b);
    answerCal.at(1) == 1 ? answer += "+" : answer += "-";
    answer += to_string(c);
    answerCal.at(2) == 1 ? answer += "+" : answer += "-";
    answer += to_string(d);
    answer += "=7";

    cout << answer << endl; 
    return 0;
}