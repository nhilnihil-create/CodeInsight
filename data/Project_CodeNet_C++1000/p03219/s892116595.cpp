#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;


int X, Y;


void input() {
    cin >> X >> Y;
}


int main() {
    input();
    int ans = X + Y / 2;
    cout << ans << endl;
}
