#include <iostream>
using namespace std;

int main() {
    int a = 0, b = 0, c = 0, d = 0;
    for (int i = 0; i < 4; i++) {
        int s;
        cin >> s;
        if (s == 1) a++;
        else if (s == 9) b++;
        else if (s == 7) c++;
        else if (s == 4) d++;
    }

    if (a == 1 && b == 1 && c == 1 && d == 1) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}