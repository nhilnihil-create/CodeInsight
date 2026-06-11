#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

int main() {
    string s;
    cin >> s;

    deque<char> dq(begin(s), end(s));
    lint ans = 0;
    while(dq.size() >= 2) {
        if(dq.front() == dq.back()) {
            dq.pop_front();
            dq.pop_back();
        } else if(dq.front() == 'x') {
            dq.pop_front();
            ans++;
        } else if(dq.back() == 'x') {
            dq.pop_back();
            ans++;
        } else {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
}