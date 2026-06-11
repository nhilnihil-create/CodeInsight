#include <bits/stdc++.h>
using namespace std;

#define int long long
const double PI = 3.14159265358979323846;
typedef vector<int> vint;
typedef pair<int, int> pint;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

string S;
int cnt[3];

signed
main() {
    cin >> S;
    for (int i = 0; i < S.length(); i++) {
        cnt[S[i] - 'a']++;
    }
    int t = 0, b = 114514;
    for (int i = 0; i < 3; i++) {
        t = max(t, cnt[i]);
        b = min(b, cnt[i]);
    }
    if (t - b <= 1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
