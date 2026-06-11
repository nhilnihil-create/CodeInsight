#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.size();
    int p[3] = {};
    for (int i = 0; i < n; i++) {
        p[s[i] - 'a']++;
    }

    sort(p, p + 3);

    cout << (p[2] - p[0] <= 1 ? "YES" : "NO") << endl;

    return 0;
}