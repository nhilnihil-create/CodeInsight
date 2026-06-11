#include <iostream>
#include <string>
#include <algorithm>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <cctype>
using namespace std;
int main() {
    int n;
    cin >> n;
    string s;
    long long ans = 0;
    long long a = 0, b = 0, c = 0;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int i = 0; i < s.size() - 1; i++) {
            if (s.substr(i, 2) == "AB") {
                ans++;
            }
        }
        if (s[0] == 'B' && s[s.size() - 1] == 'A') {
            c++;
        }
        else if (s[0] == 'B') {
            b++;
        }
        else if (s[s.size() - 1] == 'A') {
            a++;
        }
    }
    long long z = 0;
    if (a != b) {
        ans += min(a, b);
        ans += max(z, c - 1);
        long long d = min(a, b);
        a -= d;
        b -= d;
        if (c!=0){
            if (a != 0) {
                ans++;
            }
        if (b != 0) {
            ans++;
        }
        }
    }
    else if (a != 0) {
        ans += c + 1;
        ans += a - 1;
    }
    else {
        ans += max(z, c - 1);
    }
    cout << ans << endl;
    return 0;
}