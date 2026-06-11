#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w, n, sr, sc;
    cin >> h >> w >> n >> sr >> sc;
    string s, t;
    cin >> s >> t;
    int left = 1, right = w, top = 1, bottom = h;
    for (int i = n - 1; i >= 0; i--) {
        if (right < left || bottom < top) {
            cout << "NO" << endl;
            return 0;
        }
        
        if (t.at(i) == 'L' && right < w) right++;
        else if (t.at(i) == 'R' && 1 < left) left--;
        else if (t.at(i) == 'U' && bottom < h) bottom++;
        else if (t.at(i) == 'D' && 1 < top) top--;

        if (s.at(i) == 'L') left++;
        else if (s.at(i) == 'R') right--;
        else if (s.at(i) == 'U') top++;
        else if (s.at(i) == 'D') bottom--;
    }

    if (left <= sc && sc <= right && top <= sr && sr <= bottom) cout << "YES" << endl;
    else cout << "NO" << endl;
}