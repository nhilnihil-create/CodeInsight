#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    int k = 0;
    cin >> s;
    for (int i = 0; i < 3; i++)
        if (s[i] == '1') k++;
    cout << k;
}