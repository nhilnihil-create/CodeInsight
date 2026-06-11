// https://atcoder.jp/contests/abc114/tasks/abc114_c

#include <algorithm>
#include <cmath>
#include <iostream>
// #include <string>
using namespace std;
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int len = 0, cnt = 0, n;

void rege(string s) {
    // 3, 5, 7が含まれている
    if (s.find("3") != std::string::npos && s.find("5") != std::string::npos &&
        s.find("7") != std::string::npos && stoi(s) <= n) {
        cnt++;
    }
    if ((int)s.size() < len) {
        rege(s + "3");
        rege(s + "5");
        rege(s + "7");
    }

    return;
}

int main() {
    string s;
    cin >> n;

    s = to_string(n);
    len = s.size();
    rege("");

    cout << cnt << endl;
    return 0;
}
