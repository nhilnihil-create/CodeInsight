#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    int a = 0, b = 0;
    int h1 = 0, h2 = 0;

    cin >> h1;
    cin >> h2;
    b = abs(h2 - h1);

    vector<int> v(n);
    for (int i = 2; i < n; ++i) {
        int h;
        cin >> h;

        int cur = min(a + abs(h - h1), b + abs(h - h2));
        a = b;
        b = cur;
        h1 = h2;
        h2 = h;
    }
    cout << b;
}