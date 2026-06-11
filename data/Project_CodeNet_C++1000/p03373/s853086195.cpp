#include <iostream>
using namespace std;

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    
    int ans = 0;
    int mn = min(x, y);
    if(2*c < a) a = 2*c;
    if(2*c < b) b = 2*c;
    if(2*c < a + b) {
        ans += mn * 2*c;
    } else {
        ans += mn * (a + b);
    }
    
    cout << ans + (x - mn) * a + (y - mn) * b << endl;
}
