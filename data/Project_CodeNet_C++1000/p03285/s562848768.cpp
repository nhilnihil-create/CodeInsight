#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string ans = "No";
    cin >> N;
    for (int i=0;i<26;i++) {
        for (int j=0;j<15;j++) {
            if (4 * i + 7 * j == N) {
                ans = "Yes";
                break;
            }
        }
    }
    cout << ans << endl;
}
