#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    cout << 2 * count(begin(s), end(s), '+') - int(s.length()) << endl;
    return 0;
}
