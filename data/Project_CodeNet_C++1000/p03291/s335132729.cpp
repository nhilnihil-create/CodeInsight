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
long long a[100010] = { 0 }, b[100010] = { 0 }, c[100010] = { 0 };
int main() {
    string s;
    cin >> s;
    int n = s.size();
    a[0] = 0;
    b[0] = 0;
    c[0] = 0;
    long long t = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] != '?') {
            if (s[i] == 'A') {
                a[i + 1] += t;
            }
            else if (s[i] == 'B') {
                b[i + 1] += a[i];
            }
            else if (s[i] == 'C') {
                c[i + 1] += b[i];
            }
            a[i + 1] += a[i];
            b[i + 1] += b[i];
            c[i + 1] += c[i];
        }
        else {
            a[i + 1] += a[i] * 3;
            a[i + 1] += t;
            b[i + 1] += b[i] * 3;
            b[i + 1] += a[i];
            c[i + 1] += c[i] * 3;
            c[i + 1] += b[i];
            t *= 3;
        }
        a[i + 1] %= 1000000007;
        b[i + 1] %= 1000000007;
        c[i + 1] %= 1000000007;
        t %= 1000000007;
    }
    cout << c[n] % 1000000007 << endl;
}