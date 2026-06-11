#include <iostream>
#include <string>
#include <cstdint>
using namespace std;

int main() {
    int n; cin >> n;

    int64_t counter[5] = { 0 };
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        counter[0] += s[0] == 'M';
        counter[1] += s[0] == 'A';
        counter[2] += s[0] == 'R';
        counter[3] += s[0] == 'C';
        counter[4] += s[0] == 'H';
    }

    int a[] = { 0, 0, 0, 0, 0, 0, 1, 1, 1, 2 };
    int b[] = { 1, 1, 1, 2, 2, 3, 2, 2, 3, 3 };
    int c[] = { 2, 3, 4, 3, 4, 4, 3, 4, 4, 4 };

    int64_t ans = 0;
    for (int i = 0; i < 10; ++i) {
        ans += counter[a[i]] * counter[b[i]] * counter[c[i]];
    }

    cout << ans << endl;
}

