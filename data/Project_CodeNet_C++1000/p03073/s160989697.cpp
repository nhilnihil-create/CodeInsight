#include <bits/stdc++.h>
using namespace std;
int main() {
    string x;
    cin >> x;
    string one = "", two = "";
    int start = 0;
    for (int i = 0; i < x.size(); i++) {
        one += char(start + '0');
        two += (char)((start ^ 1) + '0');
        start ^= 1;
    }
    int res1 = 0, res2 = 0;
    for (int i = 0; i < x.size(); i++) {
        res1 += x[i] != one[i];
        res2 += x[i] != two[i];
    }
    cout << min(res1, res2);
    return 0;
}