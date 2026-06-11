#include<bits/stdc++.h>
using namespace std;


int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int x, y;
    cin >> x >> y;

    int ans = INT_MAX;

    for (int z = (x+y)*2; z >= 0; z--) {
        int _x = max(0, x-z/2);
        int _y = max(0, y-z/2);
        ans = min(ans, _x*a+_y*b+z*c);
    }

    cout << ans << endl;



    return 0;
}
