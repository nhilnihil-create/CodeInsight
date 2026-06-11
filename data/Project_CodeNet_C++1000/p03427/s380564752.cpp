#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define MOD 1000000007
using namespace std;
int main() {
    string s;
    cin >> s;
    int ans = 0;
    int cum = 0;
    int k = s.size();
    for (int i = 0; i < k; i++) {
        cum += (s[i] - '0');
        if (s[i] >= '1') {
            ans = max(ans, (cum - 1) + 9 * (k - 1 - i));
        }
    }
    cout << max(ans, cum) << endl;
}
