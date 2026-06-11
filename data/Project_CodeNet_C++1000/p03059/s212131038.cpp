#include <bits/stdc++.h>
using namespace std;
int main(){
    int a, b, t, ans = 0, cntr = 2, temp;
    cin >> a >> b >> t;
    temp = a;
    for(int i = 1; i <= 100; i++){
        if(i * a > t)
            break;
        ans += b;
    }
    cout << ans;
    return 0;
}
