#include <bits/stdc++.h>
using namespace std;

int palindrome(int x) {
    string s = to_string(x);
    string t = s;
    reverse(t.begin(), t.end());
    return s == t;
}

int main() {
    int a, b;
    cin >> a >> b;

    int count = 0;
    for (int i = a; i <= b; i++) {
        if (palindrome(i)) {
            count++;
        }
    }
    cout << count << endl;
}