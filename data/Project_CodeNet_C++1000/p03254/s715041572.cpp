#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N, x;
    cin >> N >> x;
    int a[110];
    int ans = 0;
    for (int i=1; i<N+1; i++) cin >> a[i];
    sort(a+1, a+N+1);
    if (x < a[1]) {
        cout << ans << endl;
    }
    else {
        for (int i=1; i<N+1; i++) {
            x -= a[i];
            if (x < 0) break;
            else ans += 1;
        }
        if (x > 0) ans -= 1;
        cout << ans << endl;
    }
    return 0;
}