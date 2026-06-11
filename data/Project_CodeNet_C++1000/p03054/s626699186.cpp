#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    int h, w, n, sr, sc;
    string s, t;
    cin >> h >> w >> n >> sr >> sc >> s >> t;
    //縦
    string s_ud(n, ' '), t_ud(n, ' ');
    for (int i = 0; i < n; i++) {
        s_ud[i] = s[i] == 'L' || s[i] == 'R' ? ' ' : s[i];
        t_ud[i] = t[i] == 'L' || t[i] == 'R' ? ' ' : t[i];
    }
    int top = 0, bottom = h + 1;
    for (int i = n - 1; i >= 0; i--) {
        if (t_ud[i] == 'U') {
            bottom = min(bottom + 1, h + 1);
        } else if (t_ud[i] == 'D') {
            top = max(top - 1, 0);
        }
        if (s_ud[i] == 'U') {
            top++;
        } else if (s_ud[i] == 'D') {
            bottom--;
        }
        if (top + 1 == bottom) {
            cout << "NO" << endl;
            return 0;
        }
    }
    if (sr <= top || sr >= bottom) {
        cout << "NO" << endl;
        return 0;
    }
    //横
    string s_lr(n, ' '), t_lr(n, ' ');
    for (int i = 0; i < n; i++) {
        s_lr[i] = s[i] == 'U' || s[i] == 'D' ? ' ' : s[i];
        t_lr[i] = t[i] == 'U' || t[i] == 'D' ? ' ' : t[i];
    }
    int left = 0, right = w + 1;
    for (int i = n - 1; i >= 0; i--) {
        if (t_lr[i] == 'L') {
            right = min(right + 1, w + 1);
        } else if (t_lr[i] == 'R') {
            left = max(left - 1, 0);
        }
        if (s_lr[i] == 'L') {
            left++;
        } else if (s_lr[i] == 'R') {
            right--;
        }
        if (left + 1 == right) {
            cout << "NO" << endl;
            return 0;
        }
    }
    if (sc <= left || sc >= right) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
}