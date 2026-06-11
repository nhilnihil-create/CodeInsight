#include <iostream>
using namespace std;

int main()
{
    int n, m, x, y; cin >> n >> m >> x >> y;
    string ans = "No War";

    int z = x + 1, xi, yi;
    for(int i = 0; i < n; i++){
        cin >> xi;
        if(xi >= z) z = xi + 1;
    }
    
    for(int i = 0; i < m; i++){
        cin >> yi;
        if(yi < z) ans = "War";
    }
    if(z > y) ans = "War";
    cout << ans << endl;
    return 0;
}
