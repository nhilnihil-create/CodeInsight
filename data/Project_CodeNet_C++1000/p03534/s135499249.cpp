#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    string s;
    cin >> s;
    int A[3] = {0, 0, 0}, i;
    for (i = 0; i < s.size(); ++i) ++A[s[i] - 'a'];
    sort(A, A + 3);
    cout << (A[2] - A[0] < 2 ? "YES" : "NO") << endl;
    return 0;
}
