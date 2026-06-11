#include <iostream>
using namespace std;

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    
    int ans = 0;
    int mn = min(x, y);
    if(2*c < a) a = 2*c;
    if(2*c < b) b = 2*c;
    
    if(2*c < a + b) cout << mn * 2*c + (x - mn) * a + (y - mn) * b << endl;
    else cout << mn * (a + b) + (x - mn) * a + (y - mn) * b << endl;
}
