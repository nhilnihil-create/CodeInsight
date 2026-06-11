#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a[3];
    for(int i = 0; i < 3; ++i) cin >> a[i];
    sort(a, a+3);
    int k; cin >> k;
    int ans = 0;
    for(int i = 0; i < 3; ++i){
        if(i == 2) for(int j = 0; j < k; ++j) a[i] *= 2;
        ans += a[i];
    }
    cout << ans << endl;
    return 0;
}