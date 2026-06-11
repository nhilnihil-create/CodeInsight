#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long

#define min(a, b) ((a) > (b) ? (b) : (a))
#define max(a, b) ((a) > (b) ? (a) : (b))

bool isPalindrome(string s) {
    string t(s.rbegin(), s.rend());
    return s == t;
}

int main(void) {
    string input[3];
    cin >> input[0] >> input[1] >> input[2];
    cout << input[0][0] << input[1][1] << input[2][2] << endl;
    return 0;
}
