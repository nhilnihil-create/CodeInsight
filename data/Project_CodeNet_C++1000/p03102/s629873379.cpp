#include <iostream>
#define int long long
using namespace std;

signed main() {
    int n,m,c;
    int b[20];
    int sum = 0;
    int ans = 0;
    int tmp = 0;

    cin >> n >> m >> c;
    for(int i = 0; i < m; i ++){
        cin >> b[i];
    }

    for(int i = 0; i < n; i ++){
        sum = c;
        for(int j = 0; j < m; j ++){
            cin >> tmp;
            sum += b[j]*tmp;
        }
        if(sum > 0) ans ++;
    }
    cout << ans;
    return 0;
}