#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<deque>
#include<map>
using namespace std;
typedef long long ll;

int main() {
    string s; cin >> s;
    int left = 0, right = (int)s.size()-1;
    int ans = 0;
    while (left < right) {
        if (s[left] == s[right]) {
            left++;
            right--;
        } else if (s[left] == 'x') {
            left++;
            ans++;
        } else if (s[right] == 'x') {
            right--;
            ans++;
        } else {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}