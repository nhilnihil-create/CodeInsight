#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s[k - 1] = tolower(s[k - 1]);
    cout << s << endl;
    return 0;
}