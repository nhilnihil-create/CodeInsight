#include<iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    int max = 0;
    int cur = 0;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c == 'A' || c == 'C' || c == 'G' || c == 'T') {
            cur++;
            max = cur > max ? cur : max;
        } else {
            cur = 0;
        }
    }
    if (cur > max) {
        max = cur;
    }

    cout << max << endl;
}