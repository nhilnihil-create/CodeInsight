#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int r, d, x;
    cin >> r >> d >> x;

    for (size_t i = 0; i < 10; i++) {
        x = r * x - d;
        cout << x << endl;
    }
    return 0;
}
