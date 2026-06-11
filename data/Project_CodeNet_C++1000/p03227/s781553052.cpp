#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string s;
    cin >> s;
    if (s.size() == 2)
        cout << s << endl;
    else {
        char t1 = s[0];
        char t2 = s[2];
        s[0] = t2;
        s[2] = t1;
        cout << s << endl;
    }

    return 0;
}