#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();

    sort(s.begin(), s.end());
    sort(t.begin(), t.end(), greater<char>());

    string ans;
    if (n < m) {
        for (int i = 0; i < n; i++) {
            if (s[i] < t[i]) {
                ans = "Yes";
                break;
            }
            else if (s[i] == t[i]) {
                ans = "Yes";
                continue;
            }
            else {
                ans = "No";
                break;
            } 
        }
    }
    else { // n >= m
        int i = 0;
        while(s[i] == t[i] && i < m) {
            i++;
        }
        if (i >= m || s[i] > t[i]) ans = "No";
        else ans = "Yes";
    }
    cout << ans << endl;
}