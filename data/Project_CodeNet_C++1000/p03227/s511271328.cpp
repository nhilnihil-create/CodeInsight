#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s; cin >> s;
    int n = s.length();
    if (n == 3) reverse(begin(s), end(s));
    cout << s << endl;
    return 0;
}
