#include <iostream>

using namespace std;

long calc(long left, long right, long left_len, long right_len) {
    return (left_len - left) + (right_len - right);
}

int main() {
    long n, left = 0, right = 0, left_len = 0;
    string s;
    cin >> n >> s;
    long right_len = n - 1;

    for (int i = 1; i < n; i++) {
        if (s[i] == 'W') {
            right++;
        }
    }

    long change = calc(left, right, left_len, right_len);
    long mini = change;

    for (int i = 1; i < n; i++) {
        if (s[i] == 'W') {
            right--;
        }

        if (s[i - 1] == 'E') {
            left++;
        }

        left_len++;
        right_len--;
        change = calc(left, right, left_len, right_len);
        mini = min(mini, change);
    }

    cout << mini << endl;
}