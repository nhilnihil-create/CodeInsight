#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main() {
    string S; cin >> S;
    int left = 0, right = S.size() - 1, ans = 0;
    while (left < right) {
        if (S[left] == 'x') {
            if (S[right] != 'x') {
                ans++; left++;
            } else {
                left++; right--;
            }
        } else if (S[right] == 'x') {
            if (S[left] != 'x') {
                ans++; right--;
            } else {
                left++; right--;
            }
        } else {
            if (S[left] != S[right]) {
                cout << -1 << endl;
                return 0;
            }
            left++; right--;
        }
    }
    cout << ans << endl;
    return 0;
}