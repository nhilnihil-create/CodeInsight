#include<bits/stdc++.h>
using namespace std;
int main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int ans = 1000000000;
    for(int i = 0; i <= max(x, y); i++){
        int m = 2*c*i + max(0, x-i)*a + max(0, y-i)*b;
        ans = min(ans, m);
    }
    cout << ans << endl;
}