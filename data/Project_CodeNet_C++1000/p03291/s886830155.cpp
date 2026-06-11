#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;


int main() {
    const int mod = 1e9 + 7;
    string s;
    cin >> s;
    long long int a = 0, b = 0, c = 0;
    long long int t = 1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'A') {
            a += t;
        } else if (s[i] == 'B') {
            b += a;
        } else if (s[i] == 'C') {
            c += b;
        } else {
            c = b + 3 * c;
            b = a + 3 * b;
            a = 3 * a + t;
            t = t * 3 % mod;
        }
        a %= mod;
        b %= mod;
        c %= mod;
        // res = (res + c) % mod;
        // cout << a << " " << b << " " << c << endl;
    }
    cout << c << endl;
}
