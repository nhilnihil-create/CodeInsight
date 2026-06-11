#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, ans;
    cin >> a >> b;
    
    int buf = a * 10 + b * 10;
    if (buf % 20 != 0) {
        ans = (buf + 10) / 20;
    } else {
        ans = buf / 20;
    }
    
    cout << ans << endl;
}
