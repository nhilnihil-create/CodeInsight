#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int ans = 0;
    bool is_find = false;
    do {
        is_find = false;
        for (int i = 0; i < (int)s.size() - 1; i++) {
            if (s.at(i) != s.at(i+1)) {
                s.erase(s.begin()+i);
                s.erase(s.begin()+i);
                ans += 2;
                is_find = true;
                break;
            }
        }
    } while(is_find);

    cout << ans << endl;
}