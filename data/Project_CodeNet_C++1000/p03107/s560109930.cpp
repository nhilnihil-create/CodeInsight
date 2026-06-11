#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int zeroCount = 0;
    int oneCount = 0;
    for (int i = 0; i <= n - 1; i++) {
        if (s[i] == '0') zeroCount++;
        else oneCount++;
    }
    cout << min(oneCount, zeroCount) * 2 << '\n';
    return 0;
}