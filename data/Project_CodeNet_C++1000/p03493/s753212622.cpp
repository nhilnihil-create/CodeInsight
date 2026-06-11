#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    cout << n / 100 + n % 10 + (n % 100 - n % 10) / 10 << endl;
    // 百の位+一の位+十の位
}