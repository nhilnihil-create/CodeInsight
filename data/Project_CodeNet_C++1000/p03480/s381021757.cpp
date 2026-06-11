#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;
    int ans = s.length();
    int n = ans - 1;
    for(int i = 0; i < n; i++) {
        if(s[i] != s[i + 1]) {
            ans = min(ans, max(i + 1, n - i));
        }
    }
    printf("%d", ans);
    return 0;
}