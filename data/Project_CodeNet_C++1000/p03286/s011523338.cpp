#include<iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s = "";
    while (n != 0) {
        if (n % -2 != 0) {
            n--;
            s = "1" + s;
        }
        else
            s = "0" + s;
        n /= -2;
    }
    if (s.empty()) {
        cout << 0 << endl;
        return 0;
    }
    cout << s << endl;
    return 0;
}
