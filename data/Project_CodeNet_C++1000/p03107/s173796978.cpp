#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pi 3.14159265359
#define inf (1 << 21)
#define mod 1000000007

int main() {
    string S; cin >> S;
    int red = 0, blue = 0;
    for (int i = 0; i < S.size(); i++) {
        if (S.at(i) == '0') {
            red++;
        }
        else {
            blue++;
        }
    }
    cout << 2 * min(red, blue) << endl;
    return 0;
}