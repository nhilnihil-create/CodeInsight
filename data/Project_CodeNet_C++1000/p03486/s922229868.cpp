#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    string s, t;
    cin >> s >> t;
    vector<char> sv, tv;
    for (int i=0; i<(int)s.length(); i++) {
        sv.push_back(s[i]);
    }
    for (int i=0; i<(int)t.length(); i++) {
        tv.push_back(t[i]);
    }
    sort(sv.begin(), sv.end());
    sort(tv.begin(), tv.end(), greater<char>());
    int minlength = min((int)s.length(), (int)t.length());
    string result;
    for (int i=0; i<minlength; i++) {
        if (sv[i] != tv[i]) {
            if (sv[i] < tv[i]) {
                result = "Yes";
            } else {
                result = "No";
            }
            break;
        } else if (i == minlength-1) {
            if (s.length() < t.length()) {
                result = "Yes";
            } else {
                result = "No";
            }
        }
    }
    cout << result << endl;
}