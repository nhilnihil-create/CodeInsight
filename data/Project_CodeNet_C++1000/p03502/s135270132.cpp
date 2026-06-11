#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    string s = to_string(n);
    int sum = 0;
    for (char x : s)
        sum += x - '0';
    if (n%sum == 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}