#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int n, T;
    int c[110], t[110];
    cin >> n >> T;
    for(int i = 0; i < n; i++) cin >> c[i] >> t[i];

    int ans = 9999;
    for(int i = 0; i < n; i++) {
        if (t[i] <= T) ans = min(ans, c[i]);
    }
    
    if (ans == 9999) cout << "TLE" << endl;
    else cout << ans << endl;
    
}