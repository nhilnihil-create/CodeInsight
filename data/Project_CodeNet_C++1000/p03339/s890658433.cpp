#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> lw(n), re(n);
    for (int i=1; i<n; i++) {
        lw[i] = lw[i-1];
        if (s[i-1] == 'W') lw[i]++;
    }
    for (int i=n-2; i>=0; i--) {
        re[i] = re[i+1];
        if (s[i+1] == 'E') re[i]++;
    }
    int ans = n;
    for (int i=0; i<n; i++) {
        ans = min(ans, lw[i] + re[i]);
    }
    cout << ans << endl;
}