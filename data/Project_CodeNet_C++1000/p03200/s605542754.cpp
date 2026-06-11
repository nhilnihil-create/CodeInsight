#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    long long ans = 0;
    long long cnt = 0;
    for (const auto& c : s) {
        if (c == 'B') cnt++;
        else ans += cnt;
    }
    cout << ans << endl;
}
