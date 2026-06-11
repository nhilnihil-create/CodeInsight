#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

#define min(a, b) ((a) > (b) ? (b) : (a))
#define max(a, b) ((a) > (b) ? (a) : (b))

#define INDEX(width, x, y) ((width) * (y) + (x))

bool isPalindrome(string s) {
    string t(s.rbegin(), s.rend());
    return s == t;
}

int main(void) {
    ll N, M;
    cin >> N >> M;
    if(N == 1 && M == 1) {
        cout << 1 << endl;
    } else if(N == 1 || M == 1) {
        cout << N * M - 2 << endl;
    } else {
        cout << (N - 2) * (M - 2) << endl;
    }
    return 0;
}
