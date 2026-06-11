#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int len = string("FESTIVAL").size();
    string s; cin >> s;
    int n = s.size();
    cout << s.substr(0, n - len) << endl;
    return 0;
}
