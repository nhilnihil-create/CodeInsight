#include <iostream>
#include <string>
using namespace std;

int main() {
    string s; cin >>s;
    int c0 = 0, c1 = 0;
    for (auto c:s) {if (c=='0') {c0++;}else{c1++;}}
    cout << min(c0,c1)*2 << endl;
    return 0;
}