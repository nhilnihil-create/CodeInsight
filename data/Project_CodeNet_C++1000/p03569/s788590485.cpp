#include <deque>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    deque<char> a(s.begin(), s.end());
    int ans = 0;
    while (1 < a.size()) {
        if (a.front() == a.back()) {
            a.pop_front();
            a.pop_back();
        }
        else if (a.front() == 'x') {
            a.push_back('x');
            ans++;
        }
        else if (a.back() == 'x') {
            a.push_front('x');
            ans++;
        }
        else {
            ans = -1;
            break;
        }
    }
    cout << ans;
}