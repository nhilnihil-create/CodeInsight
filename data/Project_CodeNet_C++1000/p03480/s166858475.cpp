#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int k = (int)s.size();

    char x = s[k/2];
    int left = (k - 1) / 2;
    int right = k / 2;

    if (s[left] != s[right]) {
        cout << k / 2 << endl;
        exit(0);
    }

    while (right < k - 1) {
        if (s[right + 1] == x) right++;
        else break;
    }
    while (left > 0) {
        if (s[left - 1] == x) left--;
        else break;
    }

    int ans = min(right - (k - 1) / 2, k / 2 - left);
    if (k % 2 == 1) ans++;

    cout << k / 2 + ans << endl;
}
