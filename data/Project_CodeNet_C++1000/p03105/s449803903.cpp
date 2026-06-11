#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for(int i = a; i < b; i++)

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    if(b / a >= c) {
        cout << c << endl;
    } else {
        cout << b / a << endl;
    }

    return 0;
}
