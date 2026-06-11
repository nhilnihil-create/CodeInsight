#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    string s;
    int left, right;
    int ans = 0;
    
    cin >> s;
        
    left = 0;
    right = s.size() - 1;
    while (left<=right) {
        if (s[left] != s[right]) {
            if (s[left] == 'x') {
                left++;
                ans++;
            } else if (s[right] == 'x') {
                right--;
                ans++;
            } else {
                ans = -1;
                break;
            }
        } else {
            left++;
            right--;
        }
    }

    cout << ans << endl;
}
