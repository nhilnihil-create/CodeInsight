#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, ans = 0;
    string s;
    cin >> n;
    int b_a = 0, sofa = 0, bed = 0;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        int l = s.size();
        int j = 0;
        while (j < l - 1) {
            if (s[j] == 'A' && s[j + 1] == 'B') {
                ++ans;
                ++j;
            }
            ++j;
        }
        if (s[0] == 'B' && s[l - 1] == 'A') ++b_a;
        else if (s[0] == 'B') ++bed;
        else if (s[l - 1] == 'A') ++sofa;
    }
    if (sofa >= 1 && bed >= 1) {
        ans += b_a + 1 + min(sofa - 1, bed - 1);
    } else if (sofa >= 1 || bed >= 1) {
        ans += b_a;
    } else {
        ans += max(b_a - 1, 0);
    }
    cout << ans << '\n';
    return 0;
}
