#include <bits/stdc++.h>
using namespace std;

int main() {
    long long l[86];
    l[0] = 2;
    l[1] = 1;
    for (int i = 2; i < 87; i++) {
        l[i] = l[i-1] + l[i-2];
    }

    int n;
    cin >> n;
    cout << l[n] << endl;
}