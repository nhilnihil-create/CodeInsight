#include <iostream>
#include <string>
using namespace std;

int main() {
    string s, ret = "WA";
    cin >> s;
    int count_c = 0, count_not_small = 0;
    string abc = "abcdefghijklmnopqrstuvxyz";
    for (int i = 2; i < s.size() - 1; ++i) {
        if (s.at(i) == 'C') {count_c++;}
    }
    for (int i = 1; i < s.size(); ++i) {
        if (abc.find(s.at(i)) == string::npos) {count_not_small++;}
    }
    if (
        s.at(0) == 'A' &&
        count_c == 1 &&
        count_not_small == 1 /* 1 is C */
    ) {ret = "AC";}
    cout << ret << endl;
    return 0;
}