#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll X, Y;

int main() {
    cin >> X >> Y;

    cout << ((X % Y == 0) ? -1 : X*(Y-1)) << endl;

    return 0;
}
