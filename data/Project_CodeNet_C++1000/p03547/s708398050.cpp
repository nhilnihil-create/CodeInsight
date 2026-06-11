#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    char X, Y;
    cin >> X >> Y;

    if (X < Y) {
        cout << "<";
    } else if (X > Y) {
        cout << ">";
    } else {
        cout << "=";
    }

    return 0;
}
