#include<iostream>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    int len = s.length();
    int j = 0;
    for(int i = 0; i < len; i++) {
        if (s == t) {
            cout << "Yes" << endl;
            return 0;
        }
        s = s.back() + s.substr(0, s.length()-1);
    }

    cout << "No" << endl;
}