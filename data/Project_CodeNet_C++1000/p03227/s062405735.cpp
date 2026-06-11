#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s; cin >> s;
    switch(s.size()) {
        case 2:
            cout << s << endl;
            return 0;
        case 3:
            reverse(s.begin(), s.end());
            cout << s << endl;
            return 0;
    }
}