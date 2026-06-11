#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;

signed main() {
    int n;
    int x;
    int a[101];
    int ans = 0;

    cin >> n;
    cin >> x;

    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }
    sort(a,a+n);

    for(int i = 0; i < n; i ++){
        if(a[i] <= x){
            x -= a[i];
            ans ++;
        } else break;
    }
    if(x != 0 && ans == n) ans --;
    cout << ans;


    return 0;
}