#include <iostream>
using namespace std;

int main() {
    string s; cin >> s;
    int n = (int)s.size();

    char center = s[n/2];
    int i = 0;
    if(n & 1) {
        for(; i <= n/2; ++i) {
            if(s[n/2 - i] != center || s[n/2 + i] != center) break;
        }
    } else {
        for(; i <= n/2; ++i) {
            if(s[n/2 - i - 1] != center || s[n/2 + i] != center) break;
        }
    }

    cout << n / 2 + i << endl;
    return 0;
}