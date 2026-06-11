#include <bits/stdc++.h>

#define rep(x, y) for (int i = (x); i < (y); i++)

typedef long long ll;

using namespace std;

int main() {
    int n;
    cin >> n;

    int a, b;
    switch (n) {
        case 1:
            cout << "Hello World";
            break;
        case 2:
            cin >> a >> b;
            cout << (a + b);
            break;
    }
    cout << endl;

    return 0;
}