#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;

int main() {
    char b;
    cin >> b;
    switch (b) {
    case 'A':
        cout << 'T' << endl;
        break;
    case 'T':
        cout << 'A' << endl;
        break;
    case 'C':
        cout << 'G' << endl;
        break;
    case 'G':
        cout << 'C' << endl;
        break;
    }
    return 0;
}