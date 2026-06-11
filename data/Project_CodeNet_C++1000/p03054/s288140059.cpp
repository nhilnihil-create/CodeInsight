#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int h, w, n;
    cin >> h >> w >> n;
    
    int r, c;
    cin >> r >> c;
    
    
    string s, t;
    cin >> s >> t;
    
    int left = 1, right = w, top = 1, bottom = h;
    
    for (int i = n - 1; i >= 0; i--) {
        switch (t[i]) {
            case 'L':
                right = min(w, right + 1);
                break;
            case 'U':
                bottom = min(h, bottom + 1);
                break;
            case 'R':
                left = max(1, left - 1);
                break;
            case 'D':
                top = max(1, top - 1);
                break;
        }
        
        switch (s[i]) {
            case 'L':
                left = left + 1;
                break;
            case 'U':
                top = top + 1;
                break;
            case 'R':
                right = right - 1;
                break;
            case 'D':
                bottom = bottom - 1;
                break;
        }
        
        if (left > right || top > bottom) {
            cout << "NO" << endl;
            return 0;
        }
    }
    
    if (left <= c && c <= right && top <= r && r <= bottom) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}