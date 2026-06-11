#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> p(n + 1), q(n + 1);
    for (int i = 0; i < n; i++) p[i + 1] = p[i] + (s[i] == '#' ? 1 : 0);
    for (int i = n - 1; i >= 0; i--) q[i] = q[i + 1] + (s[i] == '.' ? 1 : 0);

    int ret = n;
    for (int i = 0; i <= n; i++)ret = min(ret, p[i] + q[i]);
    cout << ret << endl;
    return 0;
}