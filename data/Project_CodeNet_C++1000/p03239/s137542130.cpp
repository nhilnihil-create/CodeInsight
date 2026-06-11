#include <iostream>
using namespace std;
int main(){
    int n, t;
    cin >> n >> t;
    int ans = 10001;
    for(int i = 0; i < n; i++) {
        int c, d;
        cin >> c >> d;
        if(d <= t) ans = min(ans, c);
    }
    if(ans == 10001) puts("TLE");
    else cout << ans << endl;
    return 0;
}