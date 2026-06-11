#include <bits/stdc++.h>

using namespace std;

int main() {
    int X, Y;
    cin >> X >> Y;

    int ans = -1;
    if(X % Y != 0){
        ans = X;
    }

    cout << ans << endl;
    return 0;
}