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
int lg[100010];
int rg[100010];
int a[100010];
int gcd(int a, int b) {
    if (a % b == 0) {
        return (b);
    }
    else {
        return (gcd(b, a % b));
    }
}
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    lg[1] = a[1];
    rg[n] = a[n];
    for (int i = 2; i <= n; i++) {
        lg[i] = gcd(lg[i - 1], a[i]);
    }
    for (int i = n - 1; i > 0; i--) {
        rg[i] = gcd(rg[i + 1], a[i]);
    }
    int ans = 0;
    if (ans < lg[n - 1]) {
        ans = lg[n - 1];
    }
    for (int i = 2; i < n; i++) {
        if (ans < gcd(lg[i - 1], rg[i + 1])) {
            ans = gcd(lg[i - 1], rg[i + 1]);
        }
    }
    if (ans < rg[2]) {
        ans = rg[2];
    }
    cout << ans << endl;
	return 0;
}
