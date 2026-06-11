#include <iostream>
#include <vector>
#include <algorithm>

typedef int64_t ll;
using namespace std;

int main() {
    // freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<string> w(n);
    for (auto &i: w)
        cin >> i;

    string ans  = "Yes";
    for (int i=1; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i != j && w[i] == w[j]) {
                ans = "No";
                break;
            }
        }

        if (w[i-1][w[i-1].size()-1] != w[i][0]) {
            ans = "No";
            break;
        }
    }

    cout << ans << endl;
    return 0;
}