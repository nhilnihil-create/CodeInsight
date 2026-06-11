#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int *b = new int[n], *w = new int[n]; //b[i]=i番目以上で白色の数　w[i] = i番目以下で黒色の数
    b[n-1] = (s[n-1] == '.') ? 1 : 0;
    w[0] = (s[0] == '#') ? 1 : 0;
    for (int i = 0; i < n-1; i++) {
        b[n-i-2] = (s[n-2-i] == '.') ? b[n-i-1] + 1 : b[n-i-1];
        w[i+1] = (s[i+1] == '#') ? w[i] + 1 : w[i];
    }
    int ans = min(b[0], w[n-1]);
    for (int i = 1; i < n; i++) {
        ans = min(b[i] + w[i-1], ans);
    }

    cout << ans << endl;

    return 0;
}