#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    char c;

    cin >> n >> k;
    for (int i = 0 ; i < n ; ++i) {
        cin >> c;
        if (i == k-1) cout << (char)(c + ('a'-'A'));
        else cout << c;
    }
    return 0;
}
