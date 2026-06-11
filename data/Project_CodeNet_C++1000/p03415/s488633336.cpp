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
    char input[9];
    for(int i = 0;i < 9;i++) cin >> input[i];
    cout << input[0] << input[4] << input[8] << endl;
    return 0;
}
