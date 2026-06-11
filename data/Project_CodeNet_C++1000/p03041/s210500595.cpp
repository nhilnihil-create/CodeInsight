#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    s[k - 1] = tolower(s[k - 1]);
    cout << s << endl;
    return 0;
}