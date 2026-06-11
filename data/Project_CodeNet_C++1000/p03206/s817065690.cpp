#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;

int main() {
    int d;
    cin >> d;
    if (d == 25)
        cout << "Christmas" << endl;
    else if (d == 24)
        cout << "Christmas Eve" << endl;
    else if (d == 23)
        cout << "Christmas Eve Eve" << endl;
    else if (d == 22)
        cout << "Christmas Eve Eve Eve" << endl;
    return 0;
}