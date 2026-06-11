#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pi 3.14159265359;
#define inf (1 << 21);
#define mod 1000000007;

int main() {
    int D; cin >> D;
    D %= 10;
    cout << "Christmas";
    for (int i = 0; i < 5 - D; i++) {
        cout << ' ' << "Eve";
    }
    cout << endl;
    return 0;
}